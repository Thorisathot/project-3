# Ashen Vigil

A dark-fantasy survivors-style roguelite in one HTML file. Pick an origin, descend into the halls, and hold out against the hollowed dead until the third bell tolls and the Last Warden falls (about 15 minutes).

Open `index.html` in a browser to play (the `assets/` folder must sit beside it). No build step is needed. Fonts load from Google Fonts, and the game works offline with fallback fonts.

## Controls
- **WASD / arrows**: move (armaments attack automatically)
- **Space / Shift**: dodge roll with invulnerability frames (costs stamina)
- **Q / E**: drink a tonic flask (refill at candle shrines)
- **Esc / P**: pause, **M**: sound
- Touch: drag anywhere to move, with on-screen Roll and Flask buttons

## Progression and shop
- **Hub** with Play, Armory, Shop and Altar tabs. Progress saves on the device.
- **Player level** grows from every run (kills, time survived, bosses, clears and deeper stages). Each level pays gold, every 5th adds sigils and an Iron Reliquary, and each level adds +1% damage to every run (up to +50%).
- **Gold** is earned from kills, bosses and clears. **Sigils** come from bosses and first-time stage clears (and from in-app purchases in the native app).
- **4 stages** (Undercroft, Sunken Catacombs, Ember Cathedral, Abyss Below), unlocked in order, each tougher and paying more gold.
- **Chests** (wooden, iron and ember, plus a free one every 4 hours) drop gear for 4 slots in 4 rarities, with odds shown. Gear can be upgraded to +10 or salvaged.
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
- 5 origins, 7 armaments, 7 relics, each with 5 levels
- Reliquaries dropped by elites and bosses evolve a max-level armament paired with its relic (for example Hollow Blade + Strength becomes Kingsbane)
- 3 bosses at 5, 10 and 15 minutes, with telegraphed charges, ground slams, bullet rings and spirals
- Dynamic darkness lit by your lantern, braziers, spells and candle shrines
- Synthesized sound effects and ambient drone (no audio files)

## Art
Characters, enemies, bosses, items, ability icons, chests, props, floors, stage scenes and splash art in `assets/` were generated with OpenAI's image models (gpt-image-1.5 for transparent sprites, gpt-image-2 for scenes) in one shared stylised 3D style, then trimmed, resized and compressed to WebP. If an image fails to load, the game falls back to its built-in drawn art.
