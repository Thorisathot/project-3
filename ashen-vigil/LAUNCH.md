# Launch checklist

Everything needed to get Ashen Vigil onto Google Play, in order. Items marked **(me)** are done or handled in the code; everything else is yours.

## 1. Before you sign up

- [ ] **Business address** for the public trader profile: a virtual office or mail-forwarding *street* address (PO boxes are often rejected). Keep a bill or letter showing it, in case Google asks for proof.
- [ ] **Support email** for players, for example a new Gmail like `ashenvigil.support@gmail.com`. It is shown publicly on the store page. Send it to me and I'll put it in the privacy policy.
- [ ] **12 or more Android testers** (friends and family) with Google accounts, for the required closed test.
- [ ] **Bank account** in your name for payouts.

## 2. Google Play Console — https://play.google.com/console

Sign-up:
- [ ] Choose **Personal** account (no D-U-N-S number needed).
- [ ] Pay the one-time US$25 fee and verify your identity (government ID).
- [ ] Developer name: what players see (your name or a studio name like "Ashen Studio").
- [ ] Contact email (the support email) and phone number; verify both.
- [ ] Declare **Trader** status (EU) using your business address.

Payments (needed for in-app purchases):
- [ ] **Setup > Payments profile**: link a payments profile with your business address, tax details (ABN optional for individuals in Australia) and bank account.

Create the app:
- [ ] **Create app**: name *Ashen Vigil*, language English, type **Game**, **Free**, accept the declarations.
- [ ] Package name will be `com.thorisathot.ashenvigil` (set from the first upload; tell me now if you want a different one).

App content (Policy > App content) — answers are in section 7 below:
- [ ] Privacy policy URL: `https://thorisathot.github.io/project-3/privacy.html` **(me)**
- [ ] App access: all functionality available without special access.
- [ ] Ads: **Yes, the app contains ads**.
- [ ] Content rating questionnaire.
- [ ] Target audience: **13–15, 16–17 and 18+** (not under 13).
- [ ] Data safety form.
- [ ] Government app: No. Financial features: None. Health: No. News: No.

Store listing (Grow > Store presence > Main store listing):
- [ ] Short and full description: copy from `STORE.md`.
- [ ] App icon 512x512 (`store/play/icon_512.png`), feature graphic 1024x500 (`store/play/feature_graphic_1024x500.jpg`), phone screenshots (`store/play/0*.jpg`). I'll refresh the screenshots with the new features **(me)**.
- [ ] Category: Action. Tags: Action, Roguelike, RPG.

In-app products (Monetize > Products > In-app products) — create these with exactly these IDs:
- [ ] `av_sigils_80`, `av_sigils_500`, `av_sigils_1200` (consumable sigil packs)
- [ ] `av_starter` (Pilgrim's Bundle, one-time)
- [ ] `av_urn` (Ember Urn, consumable)
- [ ] `av_wings_abyssal`, `av_wings_seraph` (wings, one-time)
- [ ] **Setup > API access**: create a service account and grant it access so RevenueCat can check purchases (RevenueCat's guide walks you through it).

Testing and release:
- [ ] **Setup > App signing**: keep **Play App Signing** on (Google holds the final key; you only hold an upload key).
- [ ] Upload the first `.aab` to **Testing > Closed testing** and add your 12+ testers by email or a Google Group.
- [ ] Keep the closed test running for **14 days** with testers opening the game.
- [ ] Then **Apply for production access**, answer the short questions, and roll out.

## 3. GitHub — https://github.com/Thorisathot/project-3

- [ ] **Upload key** (once): on your computer, run
  `keytool -genkeypair -v -keystore upload.keystore -alias upload -keyalg RSA -keysize 2048 -validity 10000`
  (keytool comes with Android Studio or any Java install). Keep the file and passwords somewhere safe and backed up.
- [ ] Turn the key into text: `base64 -w0 upload.keystore` (Mac: `base64 -i upload.keystore`; Windows PowerShell: `[Convert]::ToBase64String([IO.File]::ReadAllBytes("upload.keystore"))`).
- [ ] **Settings > Secrets and variables > Actions > New repository secret**:
  `ANDROID_KEYSTORE_BASE64`, `ANDROID_KEYSTORE_PASSWORD`, `ANDROID_KEY_ALIAS` (`upload`), `ANDROID_KEY_PASSWORD`.
- [ ] Same page, **Variables** tab: `ADMOB_APP_ID` = your real AdMob app id (after step 4).
- [ ] Build: **Actions > Android release > Run workflow**, type the version (for example `1.0.0`), then download `app-release.aab` from the finished run and upload it to Play Console. **(me: workflow ready)**
- [ ] Optional: make the repository private (then add a read-only token to Obtainium).

## 4. AdMob — https://admob.google.com

- [ ] Sign up with the same Google account; add your payment and tax details.
- [ ] **Apps > Add app**: Android, "Is the app on a store?" No for now (link it after launch).
- [ ] Copy the **app ID** (`ca-app-pub-...~...`) into the GitHub variable `ADMOB_APP_ID`.
- [ ] **Ad units > Add ad unit > Rewarded**: name it "Rewarded", reward 1 "bonus". Send me the ad unit ID (`ca-app-pub-.../...`) and I'll put it in the game.
- [ ] **Privacy & messaging**: create a **European regulations (GDPR)** message and publish it. The game already shows it to players in the EEA and UK **(me)**.
- [ ] Never tap your own live ads. Test with Google's test ads (already used in test builds).

## 5. RevenueCat — https://www.revenuecat.com

- [ ] Sign up (free until you earn US$2.5k a month).
- [ ] Create a project, add a **Google Play** app with package `com.thorisathot.ashenvigil`.
- [ ] Upload the Play service account JSON from step 2 (their guide shows how).
- [ ] Add the same product IDs as Play Console.
- [ ] Copy the **public Android SDK key** (starts with `goog_`) and send it to me; I'll put it in the game.

## 6. Later, for iPhone

- [ ] Apple Developer Program (US$99/year), a Mac with Xcode, App Store Connect listing, the same product IDs, and the RevenueCat iOS key.

## 7. Answers for Play Console forms

**Content rating (IARC)**
- Category: Game.
- Violence: yes, fantasy violence against non-human creatures (undead, monsters); not realistic. Blood: yes, stylised blood splatter. No dismemberment of humans.
- Fear/horror: mild dark fantasy themes.
- Sexuality, nudity, profanity, drugs, alcohol, tobacco, crude humour: none.
- Gambling: no real-money gambling. **In-game purchases: yes, including random items** (chests). Odds are shown in the game.
- Users interact or share content: no. Shares location: no. Unrestricted internet: no.

**Target audience and content**
- Target ages: 13–15, 16–17, 18+. Not designed for children. Store listing does not appeal to children.

**Ads**: yes, the app contains ads (optional rewarded video only).

**Data safety**
- Does the app collect or share user data? **Yes** (through AdMob and RevenueCat).
- Data encrypted in transit: **Yes**. Users can request deletion: **Yes** (by email; progress itself is only on the device).
- Collected:
  - *Device or other IDs* (advertising ID): collected and shared, for Advertising and Analytics (AdMob); App functionality (RevenueCat's anonymous app user ID).
  - *Purchase history*: collected, for App functionality (RevenueCat, restoring purchases).
  - *App interactions*: collected by AdMob for Advertising and Analytics.
  - *Approximate location* (from IP): collected by AdMob for Advertising.
  - *Crash logs and diagnostics*: collected by AdMob for Analytics.
- Not collected: name, email, contacts, photos, precise location, messages, health, financial info (Google handles payments).
- Processed ephemerally: no. Required or optional: advertising data is optional (ads are optional and consent is asked in the EEA/UK).
