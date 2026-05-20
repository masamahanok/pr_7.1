#include <stdio.h>
int main(void) {
	int n = 5, W = 10;
	int wt[] = { 2,3,4,5,1 };
	int val[] = { 3,4,5,6,1 };
	printf("Предмети:\n");
	printf("%-4s %-8s %-8s\n", "Nr", "Вага", "Цінність");
	for (int i = 0;i < n;i++)
		printf("%-4d %-8d %-8d\n", i + 1, wt[i], val[i]);
	printf("Місткість рюкзака: %d\n\n", W);
	/* Таблиця DP */
	int dp[n + 1][W + 1];
	for (int i = 0;i <= n;i++)
		for (int w = 0;w <= W;w++) {
			if (i == 0 || w == 0) { dp[i][w] = 0;continue; }
			dp[i][w] = dp[i - 1][w];
			if (wt[i - 1] <= w) {
				int v = val[i - 1] + dp[i - 1][w - wt[i - 1]];
				if (v > dp[i][w]) dp[i][w] = v;
			}
		}
	printf("Максимальна цінність: %d\n", dp[n][W]);
	/* Відновити список предметів */
	printf("Вибрані предмети: ");
	int w = W;
	for (int i = n;i > 0;i--)
		if (dp[i][w] != dp[i - 1][w]) {
			printf("Nr%d(вага=%d,цін=%d)
				",i,wt[i-1],val[i-1]);
				w -= wt[i - 1];
		}
	printf("\n");
	return 0;
}