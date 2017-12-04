int delay(unsigned int ms);
int delay(unsigned int ms)
{
	unsigned char i;
	for(;ms>0;ms--)
	{
 for(i=250;i>0;i--);
 for(i=247;i>0;i--);
	}
	return 0;
}