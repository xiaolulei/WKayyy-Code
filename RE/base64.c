char *sub_401000(int a1, int a2)
{
  int v2;         // eax
  int v3;         // esi
  size_t v4;      // ebx
  char *v5;       // eax
  char *v6;       // edi
  int v7;         // eax
  char *v8;       // ebx
  int v9;         // edi
  signed int v10; // edx
  int v11;        // edi
  signed int v12; // eax
  signed int v13; // esi
  char *result;   // eax
  char *v15;      // [esp+Ch] [ebp-10h]
  char *v16;      // [esp+10h] [ebp-Ch]
  int v17;        // [esp+14h] [ebp-8h]
  int v18;        // [esp+18h] [ebp-4h]

  v2 = a2 / 3;
  v3 = 0;
  if (a2 % 3 > 0)
    ++v2;
  v4 = 4 * v2 + 1;
  v5 = (char *)malloc(v4);
  v6 = v5;
  v15 = v5;
  if (!v5)
    exit(0);
  memset(v5, 0, v4);
  v7 = a2;
  v8 = v6;
  v16 = v6;
  if (a2 > 0)
  {
    while (1)
    {
      v9 = 0;
      v10 = 0;
      v18 = 0;
      do
      {
        if (v3 >= v7)
          break;
        ++v10;
        v9 = *(unsigned char *)(v3++ + a1) | (v9 << 8);
      } while (v10 < 3);
      v11 = v9 << 8 * (3 - v10);
      v12 = 0;
      v17 = v3;
      v13 = 18;
      do
      {
        if (v10 >= v12)
        {
          *((char *)&v18 + v12) = (v11 >> v13) & 0x3F;
          v8 = v16;
        }
        else
        {
          *((char *)&v18 + v12) = 64;
        }
        *v8++ = byte_407830[*((char *)&v18 + v12)];
        v13 -= 6;
        ++v12;
        v16 = v8;
      } while (v13 > -6);
      v3 = v17;
      if (v17 >= a2)
        break;
      v7 = a2;
    }
    v6 = v15;
  }
  result = v6;
  *v8 = 0;
  return result;
}
