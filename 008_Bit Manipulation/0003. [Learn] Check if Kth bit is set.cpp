bool isKthBitSet(int n, int k)
{
    int mask = n>>k-1;
    return mask & 1;
}



