#include <stdio.h>
#include <string.h>
#include <ctype.h>

void criptografando (char mensagem[], int chave)
{
    int i;
    char caracteres;
    
    for(i = 0; mensagem[i] != '\0'; i++)
    {
        caracteres = mensagem[i];
        
        if(isupper(caracteres))
        {
            caracteres = (caracteres - 'A' + chave) % 26 + 'A';
        }
        
        else if(islower(caracteres))
        {
            caracteres = (caracteres - 'a' + chave) % 26 + 'a';
        }
        
        mensagem[i] = caracteres;
    }
}

int main()
{
    char mensagem[100];
    int chave;
    
    printf("Escreva a mensagem que deseja criptografar\n");
    fgets(mensagem, 100, stdin);
    
    mensagem[strcspn(mensagem, "\n")] = '\0';
    
    printf("Digite a chave da criptografia\n");
    scanf("%d", &chave);
    
    criptografando(mensagem, chave);
    
    printf("Mensagem criptografada: %s\n", mensagem);
    
    return 0;
}