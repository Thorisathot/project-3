# Shipping Ashen Vigil as an app

The game is one HTML page (`index.html`). [Capacitor](https://capacitorjs.com) wraps it in a native Android and iOS shell. In-app purchases run through RevenueCat, and rewarded ads through AdMob. In a normal browser, both report "unavailable" and the game hides the purchase and ad buttons.

## Build

You need Node 20+, Android Studio (for Android) and Xcode on a Mac (for iOS).

```bash
cd ashen-vigil
npm install
npm run build            # writes www/index.html
npx cap add android      # once
npx cap add ios          # once, on a Mac
npm run android          # build, sync, open Android Studio
npm run ios              # build, sync, open Xcode
```

Run `npm run sync` again after every change to `index.html`. Commit the generated `android/` and `ios/` folders, because native settings live there.

Before publishing, change `appId` in `capacitor.config.json` from `com.example.ashenvigil` to a reverse-domain ID you own. It can't be changed after the first store release.

## Monetisation

| Lever | Where in the game | Setup needed |
|---|---|---|
| Sigil packs (IAP, consumable) | Shop, "Sigils" section | Products `av_sigils_80`, `av_sigils_500`, `av_sigils_1200` in Play Console and App Store Connect, imported into RevenueCat |
| Pilgrim's Bundle (IAP, one-time) | Shop, top card | Non-consumable or one-time consumable product `av_starter` |
| Ember Urn (IAP, consumable) | Play tab | Product `av_urn`; it gives whatever sigils the urn holds, so price it as a mid-size pack |
| Rewarded ad: double run gold | End-of-run screen | AdMob rewarded ad unit |
| Rewarded ad: skip free-chest timer | Shop, Daily Offering | Same ad unit |

Sigils buy the Ember Ark chest and trade for gold. Gold buys chests, upgrades, origins and gear upgrades, so both currencies feed the same progression.

### Keys to fill in (`STORE_KEYS` in `index.html`)

- `revenuecatAndroid`, `revenuecatIos`: public SDK keys from the RevenueCat dashboard.
- `admobRewardedAndroid`, `admobRewardedIos`: your rewarded ad unit IDs. The current values are Google's public **test** IDs. Never ship them, and never click your own live ads.
- AdMob also needs your **app ID** in the native projects: `AndroidManifest.xml` meta-data `com.google.android.gms.ads.APPLICATION_ID`, and `GADApplicationIdentifier` in iOS `Info.plist`. See the @capacitor-community/admob README.

The store code (`Platform` in `index.html`) has not been run on a device yet. Test both flows with sandbox or test accounts before release.

## Before submitting: rules that apply to this design

- **No energy system.** Runs are never limited by a timer, by design.
- **Loot box odds.** The Ember Ark can be bought with sigils, which are bought with real money. Apple (App Review Guideline 3.1.1) and Google Play both require the odds to be disclosed before purchase. The Shop already shows odds on every chest; keep them accurate if you change `CHESTS`.
- **Regional rules.** Paid loot boxes are effectively banned in Belgium, and some other countries regulate them. Either exclude those storefronts or make the Ember Ark purchasable with gold only there.
- **Ads consent.** AdMob needs a consent prompt for users in the EEA and UK (Google's UMP SDK; the AdMob plugin exposes `requestConsentInfo` and `showConsentForm`). iOS needs an App Tracking Transparency prompt if you use personalised ads.
- **Privacy policy and data safety forms.** Both stores require them because of ads and purchases.
- **Age ratings.** Fantasy violence plus purchasable random rewards affects the rating questionnaires (for example, PEGI and ESRB flag "in-game purchases (includes random items)").

## Known gaps worth fixing before launch

- **Save data is local** (`localStorage`). A reinstall loses progress, and players can edit it. Bought sigils should be restored from RevenueCat; consider cloud saves (Play Games Services, Game Center or your own backend).
- **Fonts load from Google Fonts.** Offline, the game falls back to Georgia. Bundle the Cinzel and Cormorant Garamond font files into `www/` for a consistent look.


## Icons and splash screen

`resources/` holds the source art: `icon-only.png` (1024, full icon), `icon-foreground.png` and `icon-background.png` (Android adaptive icon layers) and `splash.jpg` (2732×2732 launch screen). Generate every platform size with:

```bash
npm run assets
```

This runs `@capacitor/assets` and writes the icons and launch screens into `android/` and `ios/`. Run it after `npx cap add`.
