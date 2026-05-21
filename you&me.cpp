#include <stdio.h>
int main(void) {
	const int n = 5;                        //Кількість предметів
	const int W = 10;                       //Місткість рюкзака
	int wt[] = { 2,3,4,5,1 };               //Вага предметів
	int val[] = { 3,4,5,6,1 };              //Цінність предметів
	printf("Predmetu:\n");
	printf("%-4s %-8s %-8s\n", "Nr", "Vaha", "Tsinnost");
	for (int i = 0;i < n;i++)
		printf("%-4d %-8d %-8d\n", i + 1, wt[i], val[i]);
	printf("Mistkist ryukzaka: %d\n\n", W);
	/* Tablytsya DP(dunamychne prohramuvannya) */
	int dp[n + 1][W + 1];
	for (int i = 0;i <= n;i++)
		for (int w = 0;w <= W;w++) {
			if (i == 0 || w == 0) { 
				dp[i][w] = 0;
				continue; 
			}
			dp[i][w] = dp[i - 1][w];
			if (wt[i - 1] <= w) {
				int v = val[i - 1] + dp[i - 1][w - wt[i - 1]];//ціність попередніх предметів без ваги поточного
				if (v > dp[i][w]) dp[i][w] = v;
			}
		}

	printf("--- TABLYTSYA DP ---\n");
	for (int i = 0; i <= n; i++) {
		for (int w = 0; w <= W; w++) {
			printf("%-3d ", dp[i][w]);
		}
		printf("\n");
	}

	printf("Maksymalna tsinnost: %d\n", dp[n][W]);
	/* Vidnovyty spysok predmetiv */
	printf("Vybrani predmety: ");
	int w = W;
	for (int i = n;i > 0;i--)
		if (dp[i][w] != dp[i - 1][w]) {
			printf("Nr%d(vaha=%d,tsin=%d)",i,wt[i-1],val[i-1]);
				w -= wt[i - 1];
		}
	printf("\n");
	return 0;
}