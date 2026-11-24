# Ashen Vigil

A dark-fantasy survivors-style roguelite in one HTML file. Pick an origin, descend into the halls, and hold out against the hollowed dead until the third bell tolls and the Last Warden falls (about 10 minutes).

Open `index.html` in a browser to play (the `assets/` folder must sit beside it). No build step is needed. Fonts load from Google Fonts, and the game works offline with fallback fonts.

## Controls
- **WASD / arrows**: move (armaments attack automatically)
- **Space / Shift**: dodge roll with invulnerability frames (costs stamina)
- **Q / E**: drink a tonic flask (refill at candle shrines)
- **Esc / P**: pause, **M**: sound
- Touch: drag anywhere to move, with on-screen Roll and Flask buttons

## Signature mechanics
- **The vigil flame**: your light radius follows the flame's fuel, which burns down over time. Feed it with the Kindle card at level-ups, candle shrines and ember hearts from elites. Near it you heal and enemies slow; let it die and you fight half-blind against faster, stronger dead.
- **Parry**: press F / J / click (or the PARRY button) as an enemy strikes to stun it, and reflect projectiles back.
- **Boss posture**: bosses are tougher and their parryable attacks flash gold. Parries fill their posture bar; a full bar breaks them for 3 seconds of 2.5x damage.

## Progression and shop
- **Hub** with Play, Armory, Shop and Altar tabs. Progress saves on the device.
- **Player level** grows from every run (kills, time survived, bosses, clears and deeper stages). Each level pays gold, every 5th adds sigils and an Iron Reliquary, and each level adds +1% damage to every run (up to +50%).
- **Gold** is earned from kills, bosses and clears. **Sigils** come from bosses and first-time stage clears (and from in-app purchases in the native app).
- **4 stages** (Undercroft, Sunken Catacombs, Ember Cathedral, Abyss Below), unlocked in order, each tougher and paying more gold.
- **Chests** (wooden, iron and ember, plus a free one every 4 hours) drop gear for 8 slots (helm, armor, gloves, boots, ring, talisman, wings and a familiar) in 4 rarities, with odds shown. Gear can be upgraded to +10 or salvaged.
- **Talents**: a winding path of 36 permanent boons gated by player level, plus 4 milestone talents (extra reroll, extra flask, revive, +10% damage).
- **Stage rewards**: chests for surviving 2:00 and 5:00 and for clearing each stage.
- **Merging**: 3 pieces of gear of the same slot and rarity become 1 of the next rarity.
- **Pity counters and ten-packs** on every chest (10 for the price of 9).
- **Daily vigil** login rewards on a 7-day cycle, and the **Ember Urn**, which stores sigils from every run until it's broken open in the app.
- **Equipment screen** with your origin in the centre, gear slots around it, and total stats.
- **Origins** beyond the Knight are unlocked with gold.
- Camera zoom setting (Close, Normal, Far). Phones default to a closer camera.

A short first-run tutorial teaches movement, embers, rolling and flasks, then points new players to the talents and stage rewards.

See [STORE.md](STORE.md) for the store listing kit and [APP.md](APP.md) for building the Android and iOS apps and setting up purchases and ads.

## Features
- Dungeons tab with daily entries: Gilded Vault (gold), Crystal Reliquary (sigils), Ember Hatchery (familiars) and Trial of Bells (boss rush for a gear reliquary). Tiers open by clearing and by player level, and extra entries cost sigils
- Wings come only from the Feathers of the Fallen event (two-week seasons, feathers from hordes, bosses, clears and trials) or the shop; familiars only from the Ember Hatchery
- Carry up to 4 armaments and 4 relics per run
- Hard mode: flasks never refill and rolling has a 2 second cooldown, for +50% gold, sigils and XP
- 5 origins, 13 armaments (including one exclusive armament per stage), 7 relics, each with 5 levels
- Reliquaries dropped by elites and bosses evolve a max-level armament paired with its relic (for example Hollow Blade + Strength becomes Kingsbane)
- Boon cards show each armament's evolution relic, and relics glow when they complete a pairing for an armament you hold
- Evolution Codex in the Armory: every pairing is listed, and each evolution is revealed the first time you achieve it
- 10-minute runs with 3 bosses at 3:20, 6:40 and 10:00, plus two "the horde covets your light" onslaughts that reward a reliquary, with telegraphed charges, ground slams, bullet rings and spirals
- Dynamic darkness lit by your lantern, braziers, spells and candle shrines
- Puppet walk animation: sprites are split at the hip so legs stride while the body bobs and leans
- Performance: cached glow/gem/gore sprites, lighting, fog and vignette baked into one half-res layer, a pixel budget for large hi-DPI screens, and automatic resolution scaling if frames run long
- Synthesized sound effects and ambient drone (no audio files)

## Art
Characters, enemies, bosses, items, ability icons, chests, props, floors, stage scenes and splash art in `assets/` were generated with OpenAI's image models (gpt-image-1.5 for transparent sprites, gpt-image-2 for scenes) in one shared stylised 3D style, then trimmed, resized and compressed to WebP. If an image fails to load, the game falls back to its built-in drawn art.

## Website

`npm run build:web` builds a web version into `web/`: the same game with search and link-preview tags, an install-to-home-screen manifest and an offline cache. `.github/workflows/website.yml` publishes it to GitHub Pages on every push. In the browser, purchases and ads are hidden, and saves live in that browser.
