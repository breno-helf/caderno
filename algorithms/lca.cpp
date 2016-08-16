// LCA by Breno Moura - Não esquecer de enraizar a árvore xD

const int MAXN=11234;
const int MAXP=23;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int h[MAXN], n;

int pre[MAXN][MAXP], pai[MAXN];

vector<pii> adj[MAXN];

void dfs(int x, int u) {
  for(auto& v : adj[x]) {
    int nxt = v.first, e = v.second;
    if(nxt != u) {
      h[nxt] = h[x] + 1;
      pai[nxt] = x;
      dfs(nxt, x);
    }
  }
}

void precalc() {
  for(int i = 1; i <= n; i++) pre[i][0] = pai[i];

  // Precalculando os pais - Se guarda o k-ésimo pai.
  
  for(int k = 1; k < MAXP; k++) {
    for(int i = 1; i <= n; i++) {
      pre[i][k] = pre[pre[i][k-1]][k-1];
    }
  }
}
      
int lca(int x, int y) {
  int start = x, end = y;
  
  if(h[x] > h[y]) swap(x,y);
  int dif = h[y] - h[x];
  
  for(int i = 21; i >= 0; i--) {
    if((1<<i) <= dif) {
      y = pre[y][i];
      dif -= (1<<i);
    }
  }

  if(x != y) {
    for(int i = 21; i >= 0; i--) {
      if(pre[x][i] != pre[y][i]) {
	x = pre[x][i];
	y = pre[y][i];
      }
    }
    y = pre[y][0];
  }
  int lca = y;
  return lca;
}
