int main (){
	clock_t t = clock(); //inicia marcando um tempo
	scanf("%d %lf %lf %lf %d", &n, &l, &vs, &vb, &k);
	double i = 0., j = l;
	while((float)(clock() - t)/CLOCKS_PER_SEC < 0.7 && i < j){ //se a diferenca de tempo nao for menor q 0.7, interrompe a busca binaria
		double m = (i + j)/2.; // gasta mais um tempo fazendo a busca e checa de novo
		if(go(m))
			i = m;
		else
			j = m;
	}
	pgo(i); // realiza uma funcao qualquer com o valor encontrado
}

// Codigo de exemplo extraído de uma solucao de Gabriel Fernandes Oliveira
