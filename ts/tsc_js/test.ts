// tsconfigに "allowJs": true と "checkJs": true を指定することでJavaScriptをビルドに含み, 可能な限り型推論を行ってくれるようになる
import { sampleText, sampleFunction } from './sample'
const a = sampleFunction()
const b = sampleText