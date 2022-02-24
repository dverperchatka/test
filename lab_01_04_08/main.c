#include <stdio.h>

int get_max_amount(int kopeks)
{
	if (kopeks >= 45)
	{
		kopeks -= 20;
		int bottle_num = kopeks / 25;
		return bottle_num;
	}
	return 0;
}

int main(void)
{
	int kopeks;
	printf("Input number of kopeks: ");
	scanf("%d", &kopeks);

	int bottle_num = get_max_amount(kopeks);
	
	if (bottle_num == 1)
		printf("You can buy %d bottle of water.\n", bottle_num);
	else
		printf("You can buy %d bottles of water.\n", bottle_num);
	return 0;
}
