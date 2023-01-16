
/*
    Cộng_Trừ_Nhân_Chia 2 số lớn trong C
*/

#include <stdio.h>
#include <string.h>

int StrToNumArr(char a[], char b[], int A[], int B[])
{
    int lenA = strlen(a);
    int lenB = strlen(b);

    int len; 
    if (lenA > lenB) 
        len = lenA; 
    else 
        len = lenB; 
    lenA--; 
    lenB--;
    for (int i = len - 1; i >= 0; i--) 
    {
        if (lenA >= 0)
        {
            A[i] = a[lenA] - '0';
            lenA--;
        }
        else
            A[i] = 0;

        if (lenB >= 0)
        {
            B[i] = b[lenB] - '0';
            lenB--;
        }
        else
            B[i] = 0;
    }
    return len;
}

int SumBig(int A[], int B[], int len, int C[])
{
    for (int i = len - 1; i >= 0; i--)
    {
        if (i != 0) // 0 
        {
            int x = A[i] + B[i];
            C[i] = x % 10;
            B[i - 1] = B[i - 1] + (x / 10);
        }
        else
            C[i] = A[i] + B[i]; 
    }
    return len;
}

int ss(int A[], int B[], int len) 
{
    for (int i = 0; i < len; i++)
    {
        if (A[i] > B[i])
            return 1; 
        else if (A[i] < B[i]) 
            return -1; 
    }
    return 0; 
}

int MiBig(int A[], int B[], int len, int C[], int *dau)
{
    int hs = ss(A, B, len);
    if (hs == 0) 
        return 0;
    *dau = hs; 
    for (int i = len - 1; i >= 0; i--) 
    {
        int x;
        if (hs == 1)
            x = A[i] - B[i]; 
        else
            x = B[i] - A[i];
        if (i != 0)
        {
            if (x >= 0)
                C[i] = x;
            else
            {
                C[i] = x + 10;
                if (hs == 1) 
                    B[i - 1] = B[i - 1] + 1;
                else
                    A[i - 1] = A[i - 1] + 1;
            }
        }
        else
        {
            C[i] = x;
        }
    }
    for (int i = 0; i < len; i++)
    {
        if (C[i] != 0)
            return (len - i);
    }
}

void sc(int A[], int B[], int len)
{
    for (int i = 0; i < len; i++)
    {
        A[i] = B[i];
    }
}

int PrBig(int A[], int B[], int len, int C[])
{
    int Btg[2006];
    int Ctg[2006];
    int lenMax = 2 * len;
    for (int i = 0; i < lenMax; i++)
    {
        Btg[i] = 0;
        Ctg[i] = 0;
    }
    for (int i = len - 1; i >= 0; i--)
    {
        lenMax--;
        int k = lenMax;
        for (int j = 0; j < 2 * len; j++)
        {
            Btg[j] = 0;
        }
        for (int j = len - 1; j >= 0; j--)
        {
            int x = Btg[k] + B[i] * A[j];
            Btg[k] = (x) % 10;
            Btg[k - 1] = (x) / 10;
            k--;
        }
        SumBig(Ctg, Btg, 2 * len, C);
        sc(Ctg, C, 2 * len);
    }
    for (int i = 0; i < 2 * len; i++)
    {
        if (C[i] != 0)
            return (2 * len - i);
    }
    return 0;
}

int main()
{
    char a[1001] = "";
    char b[1001] = "";
    scanf("%s%s", a, b);
    int len;

    int As[1003];
    int Bs[1003];
    int Sum[1003];
    len = StrToNumArr(a, b, As, Bs);
    int lenSum = SumBig(As, Bs, len, Sum);
    for (int i = 0; i < lenSum; i++)
    {
        printf("%d", Sum[i]);
    } 
    printf("\n");

    int Am[1003];
    int Bm[1003];
    len = StrToNumArr(a, b, Am, Bm); 
    int Mi[1003];
    int dau = 1; 
    int lenMi = MiBig(Am, Bm, len, Mi, &dau);
    if (lenMi == 0)
        printf("0");
    else
    {
        if (dau == -1)
            printf("-");
        for (int i = len - lenMi; i < len; i++)
        {
            printf("%d", Mi[i]);
        }
    }
    printf("\n");

    int Ap[1003];
    int Bp[1003];
    len = StrToNumArr(a, b, Ap, Bp);
    int Pr[2006];
    int lenPr = PrBig(Ap, Bp, len, Pr);
    if (lenPr == 0)
        printf("0");
    else
    {
        for (int i = 2 * len - lenPr; i < 2 * len; i++)
        {
            printf("%d", Pr[i]);
        }
    }  
    return 0;
}