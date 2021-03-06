
#include "gets.h"
int GetString(char mensaje[],char str[],char error[])
{
    int esSoloLetras;

    printf("%s",mensaje);
    fflush(stdin);
    scanf("%[^\n]", str);

    esSoloLetras = Validar_Cadena(error,str);

    return esSoloLetras;
}
int Validar_Cadena(char error[],char str[])
{
    int esSoloLetras;

    esSoloLetras = 0;

    while(EsSoloLetras(str) == 0)
    {
        printf("%s",error);
        fflush(stdin);
        scanf("%[^\n]", str);

    }

    if(EsSoloLetras(str)==1)
    {
        esSoloLetras = 1;
    }

    return esSoloLetras;

}
int EsSoloLetras(char str[])
{
    int i;
    i=0;
    int retorno;

    retorno = 1;

    while(str[i] != '\0')
    {
       if((str[i]!=' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
       {
             retorno = 0;
       }
     i++;
    }


    return retorno;

}
int Validar_Numerico(char error[],char strNum[])
{
    int esNumerico;

    while(EsNumerico(strNum) == 0)
    {
        printf("%s",error);
        fflush(stdin);
        scanf("%[^\n]", strNum);
    }

    if(EsNumerico(strNum)==1)
    {
        esNumerico = (int) strtol(strNum, NULL, 10);
    }

    return esNumerico;

}
int EsNumerico(char strNum[])
{
    int i;
    int retorno;
    i=0;
    retorno = 1;
    while(strNum[i]!='\0')
    {
        if(strNum[i] < '0' || strNum[i] > '9')
        {
            retorno = 0;

        }

            i++;

    }


    return retorno;

}

int GetInt(char mensaje[],char strNum[],char error[])
{
    int esNumerico;

    esNumerico = -1;

    printf("%s",mensaje);
    fflush(stdin);
    scanf("%[^\n]", strNum);

    esNumerico = Validar_Numerico(error,strNum);

    return esNumerico;


}
int EsFlotante(char strFlotante[])
{
    int i;
    int retorno;
    int contadorPuntos;

    contadorPuntos = 0;

    retorno = 0;

    i=0;

    while(strFlotante[i]!='\0')
    {
        if((strFlotante[i] != '.') || (strFlotante[i] < '0' || strFlotante[i] > '9'))
        {
            retorno = 0;
        }
        if(strFlotante[i]=='.')
        {
            contadorPuntos++;


        }
      i++;
    }
    if(contadorPuntos==1)
    {
        retorno = 1;
    }

    return retorno;

}
float GetFloat(char mensaje[],char strFlotante[],char error[])
{
    int esFlotante;
    float flotante;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%[^\n]", strFlotante);

    esFlotante = Validar_Flotante(error,strFlotante);
    if(esFlotante == 1)
    {
    	flotante = atof(strFlotante);
    }

    return flotante;
}
int Validar_Flotante(char error[],char strFlotante[])
{
    int esFlotante;

    esFlotante = 0;

     while(EsFlotante(strFlotante)==0)
    {
        printf("%s",error);
        fflush(stdin);
        scanf("%[^\n]", strFlotante);
    }
    if(EsFlotante(strFlotante)==1)
    {
        esFlotante = 1;
    }

    return esFlotante;

}
char Validar_Caracter(char error[],char caracter,char char_Valido1,char char_Valido2)
{
    while(caracter != char_Valido1 && caracter != char_Valido2)
    {
        printf("%s", error);
        fflush(stdin);
        scanf("%c",&caracter);

    }
    return caracter;
}
char GetChar(char mensaje[], char caracter,char error[], char char_Valido1, char char_Valido2)
{

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &caracter);

    caracter = Validar_Caracter(error,caracter,char_Valido1,char_Valido2);

    return caracter;

}
int EsAlfanumerico(char str[])
{
    int i;

    int retorno;
    i = 0;
    retorno = 1;

    while(str[i]!='\0')
    {
        if((str[i]!=' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
        {
            retorno = 0;
        }

        i++;
    }

    return retorno;
}
int Validar_Alfanumerico(char error[],char str[])
{
    int esAlfanumerico;

    esAlfanumerico = 0;

    while(EsAlfanumerico(str)==0)
    {
        printf("%s",error);
        fflush(stdin);
        scanf("%[^\n]", str);

    }

    if(EsAlfanumerico(str)==1)
    {
        esAlfanumerico = 1;
    }

    return esAlfanumerico;
}
int GetAlfanumerico(char mensaje[],char str[],char error[])
{
    int esAlfanumerico;

    printf("%s",mensaje);
    fflush(stdin);
    scanf("%[^\n]", str);

    esAlfanumerico = Validar_Alfanumerico(error,str);

    return esAlfanumerico;

}
int EsTelefono(char str[])
{
    int i;
    int retorno;
    int contadorGuiones;
    contadorGuiones = 0;
    i = 0;
    retorno = 1;
    while(str[i] != '\0')
    {
        if((str[i]!='-') && (str[i] < '0' || str[i] > '9'))
        {
            retorno = 0;
        }
        if(str[i] == '-')
        {
            contadorGuiones++;

            if(contadorGuiones > 1)
            {
                retorno = 0;
            }
        }
      i++;
    }

    return retorno;

}
int ValidarTelefono(char error[],char str[])
{
    int esTelefono;

    esTelefono = 0;

    while(EsTelefono(str)==0)
    {
        printf("%s",error);
        fflush(stdin);
        scanf("%[^\n]", str);

    }
    if(EsTelefono(str)==1)
    {
        esTelefono = 1;
    }

    return esTelefono;
}
int GetTelefono(char mensaje[],char str[],char error[])
{
    int esTelefono;

    printf("%s",mensaje);
    fflush(stdin);
    scanf("%[^\n]", str);

    esTelefono = ValidarTelefono(error,str);

    return esTelefono;
}
int GetEnteroConRango(char mensaje[],char strNum[],char error[],int min, int max)
{
    int esNumerico;

    esNumerico = GetInt(mensaje,strNum,error);

    esNumerico = ValidarRangoEntero(error,esNumerico,min,max);

    return esNumerico;

}
int ValidarRangoEntero(char error[],int entero,int min,int max)
{
    while(entero < min || entero > max)
    {
        printf("%s",error);
        scanf("%d",&entero);
    }

    return entero;
}
int Menu(char mensaje[],char opcion[],char error[])
{
    int opcionNum;

    opcionNum = GetInt(mensaje,opcion,error);

    return opcionNum;
}



