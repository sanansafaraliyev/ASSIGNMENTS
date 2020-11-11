#include <stdio.h>

void function();

int main()
{
        char source[]="sanan19safaraliyev!";
        char integers[256];
        char nonintegers[256];

        function(source, integers, nonintegers);

}

void function(char *source, char *integers, char *nonintegers)
{
        int i,k;
	int a=0,b=0;
     
        for (i=0; source[i] !='\0';i++)
        {
                if (source[i]>=48 && source[i]<=57)
                {
                        integers[a]=source[i];
			a++;
                        
                }
                else
                {
                        nonintegers[b]=source[i];
			b++;
                       
                }
	
        }
	integers[a]='\0';
	nonintegers[b]='\0';

        printf("\nThe elements of the integers:");
        for (k=0;integers[k] != '\0';k++)
        {
                printf("%c",integers[k]);
        }
	printf("\n");

	printf("\nThe elements of the nonintegers:");

	for (k=0;nonintegers[k] != '\0';k++)
	{
		printf("%c",nonintegers[k]);
	}
	printf("\n");
}

