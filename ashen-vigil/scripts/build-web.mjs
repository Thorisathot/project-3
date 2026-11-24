// Builds the public website version of the game into web/ (deployed to GitHub Pages).
// Same game page as the app, plus a full <head> for search and link previews, an
// install-to-home-screen manifest, and an offline cache.
import { readFileSync, writeFileSync, mkdirSync, cpSync, rmSync, existsSync } from 'node:fs';
import { dirname, join } from 'node:path';
import { fileURLToPath } from 'node:url';

const root = join(dirname(fileURLToPath(import.meta.url)), '..');
const out = join(root, 'web');
const body = readFileSync(join(root, 'index.html'), 'utf8').replace(/<title>[^<]*<\/title>\s*/, '');
const desc = 'Ashen Vigil is a dark-fantasy survivors roguelite. Hold the last flame against endless hollowed dead, evolve your armaments, break bosses with perfect parries and raid daily dungeons. Free to play in your browser.';
const html = `<!doctype html>
<html lang="en">
<head>
<meta charset="utf-8">
<title>Ashen Vigil · Dark-fantasy survivors roguelite</title>
<meta name="description" content="${desc}">
<meta name="viewport" content="width=device-width,initial-scale=1,maximum-scale=1,user-scalable=no,viewport-fit=cover">
<meta name="theme-color" content="#07060a">
<meta name="apple-mobile-web-app-capable" content="yes">
<meta name="mobile-web-app-capable" content="yes">
<meta name="apple-mobile-web-app-status-bar-style" content="black-translucent">
<meta name="apple-mobile-web-app-title" content="Ashen Vigil">
<meta property="og:type" content="website">
<meta property="og:title" content="Ashen Vigil">
<meta property="og:description" content="${desc}">
<meta property="og:image" content="og.jpg">
<meta name="twitter:card" content="summary_large_image">
<link rel="manifest" href="manifest.webmanifest">
<link rel="icon" type="image/png" sizes="32x32" href="icon-32.png">
<link rel="apple-touch-icon" href="icon-180.png">
<style>:root{padding-top:env(safe-area-inset-top,0px);padding-bottom:env(safe-area-inset-bottom,0px)}html,body{margin:0;background:#07060a;overscroll-behavior:none}[hidden]{display:none!important}</style>
</head>
<body>
${body}
<script>if ('serviceWorker' in navigator && location.protocol === 'https:') addEventListener('load', () => navigator.serviceWorker.register('sw.js').catch(() => {}));</script>
</body>
</html>
`;
if (existsSync(out)) rmSync(out, { recursive: true });
mkdirSync(out, { recursive: true });
writeFileSync(join(out, 'index.html'), html);
cpSync(join(root, 'assets'), join(out, 'assets'), { recursive: true });
cpSync(join(root, 'web-static'), out, { recursive: true });
writeFileSync(join(out, '.nojekyll'), '');
console.log('Built web/ (' + Math.round(html.length / 1024) + ' KB page)');
