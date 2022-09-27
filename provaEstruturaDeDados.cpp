#include <stdio.h>

struct Professores
{
	char nome[20];
	char sexo;
	float horaAula;
	float SB;
	float SL;
	float desconto;
};


void lerDados(struct Professores p[])
{
     int i;
 	 for(i = 0; i<3; i++)
 	{
		printf("\n Digite o nome: ");
		scanf("%s", p[i].nome);
		printf("\n Digite o sexo usando M(masculino) F(feminino): ");
		scanf(" %c", &p[i].sexo);
		printf("\n Dgite as horas aulas: ");
		scanf("%f", &p[i].horaAula);
   } 				
}
	
void calculos(struct Professores p[])
{  
	int i;
		 	
 	for(i=0; i<3; i++)
   {
	 	p[i].SB = p[i].horaAula *85;
	
	 	if(p[i].sexo == 'M' || p[i].sexo == 'm')
	   {
		 	if(p[i].horaAula <= 70)
			{
			 	p[i].desconto = 0.10 * p[i].SB;
			}
			else 
			{
			 	p[i].desconto = 0.08* p[i].SB;
			} 
	   }
	   else  // sexo feminino
	  {
	 	 if(p[i].horaAula <= 70)
		{
		 	p[i].desconto = 0.07 * p[i].SB;
        }
		else 
		{
		 	p[i].desconto = 0.05* p[i].SB;
		} 
	 }	
	 
	 p[i].SL = p[i].SB - p[i].desconto;
	
	}  // fim do for
}	//fm da função

int main()
{
	int i;
	struct Professores p[3];
	
	int fem = 0;
	float somaSL = 0;
	float mediaSLFem = 0;
	
	
	lerDados(p);
	calculos(p);
    
    //CALCULO DA MEDIA
	for(i=0; i<3 ; i++)
	{
	 	if (p[i].sexo == 'F' || p[i].sexo == 'f')
    	 {
				 	somaSL = somaSL + p[i].SL;
				 	fem++;
         }
	}
    mediaSLFem = somaSL/fem;
			 
	printf("\n Media = %.2f", mediaSLFem);
		 
		 
	
	return 0;
}
