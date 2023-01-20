int mi_fun()
{
    static int i;
    i++;
    return (i);
}

int main()
{
    int j;

    j = 0;
    while (1)
        j =mi_fun();
    return 0;
}