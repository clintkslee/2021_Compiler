int k = 0;
float fv = 3.0;
for (int i = 0; i < 10; i++)
{
	if (i > 9)
		continue;
	k = k % 3;
	switch (k) {
	case 0:
		k = k + 1;
		break;
	case 1:
		k++;
		break;
	default:
		fv = fv - 0.1;
		break;
}