// Union-find by Breno Moura e Enzo Nakamura- Use com rank ou size =D
// INICIALIZA AS PARADA MEU!!!!
int h[MAXN], pai[MAXN], comp; // Rank, pai e numero de componentes.

int raiz(int a) {
  if(pai[a] == a) return a;
  else return pai[a] = raiz(pai[a]);
}

bool busca(int a, int b) {
  if(raiz(a) == raiz(b)) return 1;
  else return 0;
}

void une(int a, int b) {
  a = raiz(a);
  b = raiz(b);
  if(busca(a,b) == 1) return;
  comp--;
  if(h[b] > h[a]) swap(a,b);
  if(h[a] == h[b]) h[a]++;
  //sz[a] += sz[b];
  pai[b] = a;
}
