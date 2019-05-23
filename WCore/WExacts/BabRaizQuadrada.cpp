\\Algoritmo babilônico para calcular a raiz quadrada:

racional raiz_quadrada (racional n)
	{
		racional suposição, resultante;
		suposição = n / 2;
		para (inteiro i = 0; i < 10; i++)
		{
			resultante = n / suposição;
			suposição = (suposição + resultante) / 2;
		}
		retornar suposição;
	}