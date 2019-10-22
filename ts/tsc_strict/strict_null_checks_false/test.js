// 通常, nullを代入された変数はnull型として推論され, 他の型を代入しようとすると警告が出るが,
// tsconfigで "strictNullChecks": false とされている場合, そのチェックが抑止される
var nullable = null;
nullable = 'string';
