struct seg{
  // coloque aqui os parametros de sua seg =D
  // int soma;
  // sei la cara inventa ae
}tree[4*MAXN];

void build(int id, int l, int r) {
  // Aqui é body builder? Não, mas é seg builder!!!
  if(l == r){
    // tree[id].soma = default
    // inicializações default de acordo com array
  }
  else {
    int mid = (l + r)/2;
    int esq = 2*id, dir = 2*id + 1;
    build(esq, l, mid);
    build(dir, mid + 1, r);
    // E aqui você constrói seu nó, juntando ele com os dois filhos
  }
}

void update_ponto(int id, int l, int r, int pos, int val) {
  if(l == r) {
    //Aí vc da update na pos;
  }

  else {
    int mid = (l + r)/2;
    int esq = 2*id, dir = 2*id + 1;
    if(pos <= mid) update_ponto(esq, l, mid, pos, val);
    else update_ponto(dir, mid + 1, r, pos, val);
    // junta os nós pq vc mudou em baixo;
  }
}

void update_intervalo(int id, int l, int r, int lo, int hi, int val) {
  if(l > hi || r < lo) return;
  if(l >= lo && r <= hi){
    // faz os update ae sepa ate umas lazy
  }
  
  int mid = (l + r)/2, esq = 2*id, dir = 2*id + 1;
  
  update_intervalo(esq, l, mid, lo, hi, val);
  update_intervalo(dir, mid + 1, r, lo, hi, val);

  // atualiza os nós pq vc mudou em baixo

}

seg query(int id, int l, int r, int lo, int hi) {
  seg ret;
  // inicializa a seg --
  if(l > hi || r < lo) return ret;
  if(l >= lo && r <= hi) return tree[id];
  int mid = (l + r)/2;
  seg esq = query(2*id, l, mid, lo, hi);
  seg dir = query(2*id + 1, mid + 1, r, lo, hi);
  // junta os filho pra formar o papi;
  return ret;
}
