#include <stdio.h>
void solve(int i, int m, int n, int *nums, int *ans)
{
    if (i >= n)
        return;
    if (i == n - 1)
    {
        if (m < ans)
            ans = m;
    }
    solve(i + 1, m + 1, n, nums, ans);
    solve(i + nums[i], m + 1, n, nums, ans);
}
int minJumps(int n, int *nums)
{
    int ans = 100000;
    solve(0, 0, n, nums, &ans);
    return ans;
}
int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int ans = minJumps(n, arr);
    printf("%d", ans);
    return 0;
}