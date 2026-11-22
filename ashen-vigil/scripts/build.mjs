// Wraps the game page (index.html, written as an HTML fragment) into a full
// document for the native app and writes it to www/index.html.
import { readFileSync, writeFileSync, mkdirSync, cpSync, existsSync } from 'node:fs';
import { dirname, join } from 'node:path';
import { fileURLToPath } from 'node:url';

const root = join(dirname(fileURLToPath(import.meta.url)), '..');
const body = readFileSync(join(root, 'index.html'), 'utf8');
const html = `<!doctype html>
<html lang="en">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width,initial-scale=1,maximum-scale=1,user-scalable=no,viewport-fit=cover">
<meta name="theme-color" content="#07060a">
<style>:root{padding-top:env(safe-area-inset-top,0px);padding-bottom:env(safe-area-inset-bottom,0px)}body{margin:0}[hidden]{display:none!important}</style>
</head>
<body>
${body}
</body>
</html>
`;
mkdirSync(join(root, 'www'), { recursive: true });
writeFileSync(join(root, 'www', 'index.html'), html);
if (existsSync(join(root, 'assets'))) cpSync(join(root, 'assets'), join(root, 'www', 'assets'), { recursive: true });
console.log('Built www/index.html (' + Math.round(html.length / 1024) + ' KB)');
