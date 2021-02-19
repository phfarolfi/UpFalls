#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#define SCREAN_WIDTH 1280
#define SCREAN_HEIGHT 720

int VidaDipper=3;
int Pontuacao=0;
int Chave=0;

FILE *p;
FILE *f;
void pont(){
    f=fopen("ranking.txt","r");
    p=fopen("ranking.txt","w");
    int aux;
    char aux2;
    char nomes[5];
    int pontuacoes[5];
    char nome[15];
    printf("Digite seu nome:\n");
    scanf("%s[^\n]",nome);
    for(int i=0;i<5;i++){
        fscanf(p,"%s ",nomes[i]);
        fscanf(f,"%d",&pontuacoes[i]);

    }
    if(Pontuacao>pontuacoes[4]){
        pontuacoes[4]=Pontuacao;
        nomes[4]='K';
    }
    for(int j=0;j<15;j++){
        if(pontuacoes[j]<pontuacoes[j+1]){
            aux=pontuacoes[j+1];
            aux2=nomes[j+1];
            pontuacoes[j+1]=pontuacoes[j];
            nomes[j+1]=nomes[j];
            pontuacoes[j]=aux;
            nomes[j]=aux2;
        }
    }
    for(int k=0;k<5;k++){
        fprintf(p,"%s ",nomes[k]);
        fprintf(p,"%d",pontuacoes[k]);
        fprintf(p,"\n");
    }

    for(int l=0;l<5;l++){
        if(nomes[l]=='K'){
            printf("Sua pontua��o � %d\n",l);

        }
    }
}

int distancia (int x1,int y1,int x2,int y2){
    int resultado;
    resultado=sqrt(pow((x1-x2),2)+pow((x1-x2),2));
    return resultado;
}

//Estruturas
struct {
    SDL_Rect sRect = {0, 0, 89, 157};
    SDL_Rect dRect = {0, 600, 44, 78};
    SDL_Point vel = {15, -10};
} dipper;

struct {
    SDL_Rect dRect = {0, 675, 1456, 45};
} plat;

struct {
    SDL_Rect sRect = {0, 0, 116, 138};
    SDL_Rect dRect = {950, 630, 38, 46};
    SDL_Point vel = {10, -10};
} ini;

struct {
    SDL_Rect sRect = {0, 0, 115, 138};
    SDL_Rect dRect = {90, 406, 38, 46};
    SDL_Point vel = {10, -10};
} ini1;

struct{
    SDL_Rect sRect = {0,0,116,138};
    SDL_Rect dRect = {950, 180, 38, 46};
    SDL_Point vel = {7, -7};
} ini2;

struct {
    SDL_Rect sRect = {0, 0, 496, 103};
    SDL_Rect dRect = {-248, 5, 248, 51};
    SDL_Point vel = {4};
} clo;

struct {
    SDL_Rect sRect = {0, 0, 622, 246};
    SDL_Rect dRect = {640, 5, 311, 123};
    SDL_Point vel = {4};
} clo2;

struct {
    SDL_Rect sRect = {0, 0, 523, 110};
    SDL_Rect dRect = {250, 5, 262, 55};
    SDL_Point vel = {5};
} clo3;

struct {
    SDL_Rect sRect = {0, 0, 277, 108};
    SDL_Rect dRect = {880, 5, 138, 54};
    SDL_Point vel = {6};
} clo4;

struct{
    SDL_Rect sRect={0,0,81,81};
    SDL_Rect dRect={900,620,45,45};
}moeda;

struct {
    SDL_Rect dRect={0,450,1456, 45};
}plataforma1;

struct{
    SDL_Rect dRect={0,225,1456, 45};
}plataforma2;

struct{
    SDL_Rect sRect = {0, 0, 127, 233};
    SDL_Rect dRect = {1180, 605, 35, 75};
}mabel;

struct{
    SDL_Rect sRect={0,0,159,234};
    SDL_Rect dRect={1190,560,70,117};
}portal;

struct{
    SDL_Rect dRect={5,335,70,117};
}portal2;

struct{
    SDL_Rect dRect={1190,335,70,117};
}portal3;

struct{
    SDL_Rect dRect={630,108,70,117};
}portal4;

struct{
    SDL_Rect dRect={1190,100,70,117};
}portal5;

//moedas
struct{
    SDL_Rect dRect={450,620,45,45};//primeira
}moeda2;

struct{
    SDL_Rect dRect={225,393,45,45};//terceira
}moeda3;

struct{
    SDL_Rect dRect={675,393,45,45};//quarta
}moeda4;

struct{
    SDL_Rect dRect={450,165,45,45};//quita
}moeda5;

struct{
    SDL_Rect dRect={900,165,45,45};//sexta
}moeda6;
//fim das moedas

//inicio dos cora�oes
struct{
    SDL_Rect sRect={0,0,56,51};
    SDL_Rect dRect={10,10,28,25};
}vida;

struct{
    SDL_Rect sRect={0,0,56,51};
    SDL_Rect dRect={66,10,28,25};
}vida2;

struct{
    SDL_Rect sRect={0,0,56,51};
    SDL_Rect dRect={122,10,28,25};
}vida3;
//fim dos cora�oes

//estruturas da segunda fase{

struct{
    SDL_Rect dRect={5,565,70,117};
}portal6;

struct{
    SDL_Rect dRect={5,108,70,117};
}portal7;

struct{
    SDL_Rect dRect={1190,565,70,117};
}portal8;

struct{
    SDL_Rect dRect ={-50,655,1424,90};
}pisocav;

struct{
    SDL_Rect dRect={-50,200,1456, 70};
}platcaver;

struct{
    SDL_Rect dRect={-50,430,1456,70};
}platcaver2;

struct{
    SDL_Rect dRect= {720,75,90,150};
}paredechave;

struct{
    SDL_Rect sRect= {0,0,216,214};
    SDL_Rect dRect= {-50,500,230,190};

}ultcav;

struct{
    SDL_Rect sRect= {0,0,256,213};
    SDL_Rect dRect= {1050,40,280,190};

}cavernadire;

struct{
    SDL_Rect sRect= {0,0,216,214};
    SDL_Rect dRect= {-50,40,230,190};

}cavernadies;

struct{
    SDL_Rect sRect= {0,0,185,258};
    SDL_Rect dRect= {500,600,50,85};
}Key1;



//Globais
SDL_Event evento;

int main(int argc, char* args[]){

    //Main
    int gaming = 1;
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* janela0 = SDL_CreateWindow("Gravity Falls",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, SCREAN_WIDTH,SCREAN_HEIGHT,SDL_WINDOW_SHOWN);
    SDL_Renderer* render0 = SDL_CreateRenderer(janela0, -1, SDL_RENDERER_ACCELERATED);
    SDL_Surface* surf;


    //musica

    /*int frequencia= 22050;
    Uint16 formato = AUDIO_S16SYS;
    int canais = 1;
    int buffer = 4096;

    Mix_OpenAudio(frequencia,formato,canais,buffer);

    Mix_Chunk* som;
    som = Mix_LoadWAV("musicafundo.wav");
    Mix_PlayChannel(-1,som,-1);*/

    //Cria��o de Textura
    surf = SDL_LoadBMP("fundo.bmp");
    SDL_Texture* textura_fundo = SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("caverna.bmp");//fundo da caverna iniciando, tutu pom
    SDL_Texture* fundo_caverna = SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("tutorial.bmp");
    SDL_Texture* tutorial = SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("win.bmp");
    SDL_Texture* win = SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("lose.bmp");
    SDL_Texture* lose = SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("menu.bmp");
    SDL_Texture* menu1 = SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("move.bmp");
    SDL_Texture* textura1 = SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("invmove.bmp");
    SDL_Texture* textura2 = SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("plat.bmp");
    SDL_Texture* plataforma = SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("enemy.bmp");
    SDL_Texture* inimigo = SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("enemy2.bmp");
    SDL_Texture* inimigo1 = SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("cloud.bmp");
    SDL_Texture* nuvem = SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("cloud2.bmp");
    SDL_Texture* nuvem2 = SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("cloud3.bmp");
    SDL_Texture* nuvem3 = SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("cloud4.bmp");
    SDL_Texture* nuvem4 = SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("jump1.bmp");
    SDL_Texture* pulo1 = SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("jump2.bmp");
    SDL_Texture* pulo2 = SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = IMG_Load("moeda.png");
    SDL_Texture* moedao1 = SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = IMG_Load("moeda.png");
    SDL_Texture* moedao2 = SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = IMG_Load("moeda.png");
    SDL_Texture* moedao3 = SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = IMG_Load("moeda.png");
    SDL_Texture* moedao4 = SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = IMG_Load("moeda.png");
    SDL_Texture* moedao5 = SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = IMG_Load("moeda.png");
    SDL_Texture* moedao6 = SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("plat.bmp");
    SDL_Texture* plataformapri=SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("plat.bmp");
    SDL_Texture* plataformaseg=SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("mabel.bmp");
    SDL_Texture* mabel1=SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("portal.bmp");
    SDL_Texture* portal1=SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("coracao.bmp");
    SDL_Texture* core=SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("coracao.bmp");
    SDL_Texture* core1=SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("coracao.bmp");
    SDL_Texture* core2=SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("enemy.bmp");
    SDL_Texture* inimigo2 = SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("cavernapiso.bmp");
    SDL_Texture* platcav= SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("cavernadi.bmp");
    SDL_Texture* entrada1= SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("cavernaes.bmp");
    SDL_Texture* entrada2= SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("caverplat.bmp");
    SDL_Texture* platcav2= SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("Paredesemchave.bmp");
    SDL_Texture* parede= SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("Key.bmp");
    SDL_Texture* key= SDL_CreateTextureFromSurface(render0,surf);
    SDL_FreeSurface(surf);


    SDL_Texture* textura0 = textura1;
    int dist,dist1,dist2,dist3,dist4,dist5;
    int distanciaportal1,distancaiportal2;
    int distanciaini1,distanciaini2,distanciaini3;
    int distanciamabel;
    int menu = 0;
    int moveX, moveY;
    int distanciacav1,distanciacav2;


    //Game Loop
    while(gaming == 1){

        if(menu == 0){
            SDL_RenderClear(render0);
            SDL_RenderCopy(render0,menu1,NULL,NULL);
            while(SDL_PollEvent(&evento)){
                if(evento.type == SDL_MOUSEMOTION){
                    moveX = evento.motion.x;
                    moveY = evento.motion.y;
                }
                if(evento.type == SDL_MOUSEBUTTONDOWN){
                    if (moveX >= 0 && moveX <= 220 && moveY >= 350 && moveY <= 470 && evento.button.button == SDL_BUTTON_LEFT){
                        menu=1;
                    }
                    if (moveX >= 0 && moveX <= 300 && moveY >= 470 && moveY <= 590 && evento.button.button == SDL_BUTTON_LEFT){
                        menu=2;
                    }
                }
            }
        }

        if(menu == 1){
            SDL_RenderClear(render0);
            SDL_RenderCopy(render0, textura_fundo, NULL, NULL);

            SDL_RenderCopy(render0, plataforma, NULL, &plat.dRect);

            SDL_RenderCopy(render0, portal1, &portal.sRect, &portal.dRect);
            SDL_RenderCopy(render0, portal1, &portal.sRect, &portal2.dRect);
            SDL_RenderCopy(render0, portal1, &portal.sRect, &portal3.dRect);
            SDL_RenderCopy(render0, portal1, &portal.sRect, &portal4.dRect);

            SDL_RenderCopy(render0, moedao1, &moeda.sRect, &moeda.dRect);
            SDL_RenderCopy(render0, moedao2, &moeda.sRect, &moeda2.dRect);
            SDL_RenderCopy(render0, moedao3, &moeda.sRect, &moeda3.dRect);
            SDL_RenderCopy(render0, moedao4, &moeda.sRect, &moeda4.dRect);
            SDL_RenderCopy(render0, moedao5, &moeda.sRect, &moeda5.dRect);
            SDL_RenderCopy(render0, moedao6, &moeda.sRect, &moeda6.dRect);

            SDL_RenderCopy(render0, entrada1, &cavernadire.sRect, &cavernadire.dRect);
            SDL_RenderCopy(render0, entrada2, &cavernadies.sRect, &cavernadies.dRect);

            SDL_RenderCopy(render0, plataformapri, NULL, &plataforma1.dRect);
            SDL_RenderCopy(render0, plataformaseg, NULL, &plataforma2.dRect);

            SDL_RenderCopy(render0, inimigo, &ini.sRect, &ini.dRect);
            SDL_RenderCopy(render0, inimigo1, &ini1.sRect, &ini1.dRect);
            SDL_RenderCopy(render0, inimigo2, &ini2.sRect, &ini2.dRect);

            SDL_RenderCopy(render0, nuvem, &clo.sRect, &clo.dRect);
            SDL_RenderCopy(render0, nuvem2, &clo2.sRect, &clo2.dRect);
            SDL_RenderCopy(render0, nuvem3, &clo3.sRect, &clo3.dRect);
            SDL_RenderCopy(render0, nuvem4, &clo4.sRect, &clo4.dRect);


            SDL_RenderCopy(render0, textura0, &dipper.sRect, &dipper.dRect);

            SDL_RenderCopy(render0, core, &vida.sRect, &vida.dRect);
            SDL_RenderCopy(render0, core1, &vida2.sRect, &vida2.dRect);
            SDL_RenderCopy(render0, core2, &vida3.sRect, &vida3.dRect);

            if(ini.dRect.x>=-50){
                ini.dRect.x += ini.vel.y;
                ini.sRect.x += 116;
                if(ini.dRect.x<-46){
                    ini.dRect.x = 1280;
                }
                if(ini.sRect.x >= 463){
                    ini.sRect.x = 0;
                }
            }
            if(ini1.dRect.x<=1300){
                ini1.dRect.x += ini1.vel.x;
                ini1.sRect.x += 116;
                if(ini1.dRect.x>1300){
                    ini1.dRect.x = -50;
                }
                if(ini1.sRect.x >= 463){
                    ini1.sRect.x = 0;
                }
            }
            if(ini2.dRect.x>=-50){
                ini2.dRect.x += ini2.vel.y;
                ini2.sRect.x += 116;
                if(ini2.dRect.x<70){
                    ini2.dRect.x = 1130;
                }
                if(ini2.sRect.x >= 463){
                    ini2.sRect.x = 0;
                }
            }

            //NUVENS//
            if(clo.dRect.x<1280){
                clo.dRect.x += clo.vel.x;
                if(clo.dRect.x >= 1280){
                    clo.dRect.x = -250;
                }
            }
            if(clo2.dRect.x<1280){
                clo2.dRect.x += clo2.vel.x;
                if(clo2.dRect.x >= 1280){
                    clo2.dRect.x = -311;
                }
            }
            if(clo3.dRect.x<1280){
                clo3.dRect.x += clo3.vel.x;
                if(clo3.dRect.x >= 1280){
                    clo3.dRect.x = -262;
                }
            }
            if(clo4.dRect.x<1280){
                clo4.dRect.x += clo4.vel.x;
                if(clo4.dRect.x >= 1280){
                    clo4.dRect.x = -138;
                }
            }

            //FIM DAS NUVENS//
            if(dipper.dRect.y!=600 && dipper.dRect.y!=375 && dipper.dRect.y!=150){
                    dipper.dRect.y+=10;
            }
            //distancia das moedas e portais
            dist = distancia(dipper.dRect.x,dipper.dRect.y,moeda.dRect.x,moeda.dRect.y);
            dist1= distancia(dipper.dRect.x,dipper.dRect.y,moeda2.dRect.x,moeda2.dRect.y);
            dist2= distancia(dipper.dRect.x,dipper.dRect.y,moeda3.dRect.x,moeda3.dRect.y);
            dist3= distancia(dipper.dRect.x,dipper.dRect.y,moeda4.dRect.x,moeda4.dRect.y);
            dist4= distancia(dipper.dRect.x,dipper.dRect.y,moeda5.dRect.x,moeda5.dRect.y);
            dist5= distancia(dipper.dRect.x,dipper.dRect.y,moeda6.dRect.x,moeda6.dRect.y);
            distanciaportal1= distancia(dipper.dRect.x,dipper.dRect.y,1190,560);
            distancaiportal2= distancia(dipper.dRect.x,dipper.dRect.y,5,335);

            distanciaini1 = distancia(dipper.dRect.x,dipper.dRect.y,ini.dRect.x,ini.dRect.y);
            distanciaini2 = distancia(dipper.dRect.x,dipper.dRect.y,ini1.dRect.x,ini1.dRect.y);
            distanciaini3 = distancia(dipper.dRect.x,dipper.dRect.y,ini2.dRect.x,ini2.dRect.y);

            distanciacav1 = distancia(dipper.dRect.x,dipper.dRect.y,1190,150);
            distanciacav2 = distancia(dipper.dRect.x,dipper.dRect.y, 50,150);


            portal.sRect.x+=161;
            if(portal.sRect.x>=638){
                portal.sRect.x = 1;
            }


            moeda.sRect.x+=81;
            if(moeda.sRect.x>546){
                moeda.sRect.x=0;
            }

            if(distanciacav1<=10 && dipper.dRect.y<=160){
                menu=10;
                dipper.dRect.y=140;
                dipper.dRect.x=150;

            }
            if(distanciacav2<=10 && dipper.dRect.y<=160){
                menu=11;
                dipper.dRect.y=140;
                dipper.dRect.x=1070;

            }

            /*if(dipper.dRect.x>100){
                menu=10;
                dipper.dRect.y=150;
            }*/


            if(dist<=10 && dipper.dRect.y>=600){
                Pontuacao+=10;
                moeda.sRect.x=567;
                moeda.dRect.x=7000;
                moeda.dRect.y=5000;
                if(moeda.sRect.x == 567){
                SDL_DestroyTexture(moedao1);
                }
            }
            if(dist1<=10 && dipper.dRect.y==600){
               Pontuacao+=10;
               moeda.sRect.x=567;
               SDL_DestroyTexture(moedao2);
               moeda2.dRect.x=7000;
               moeda2.dRect.y=5000;
            }
            if(dist2<=10 && dipper.dRect.y==375){
                Pontuacao+=10;
                moeda.sRect.x=567;
                SDL_DestroyTexture(moedao3);
                moeda3.dRect.x=7000;
                moeda3.dRect.y=5000;
            }
            if(dist3<=10 && dipper.dRect.y==375){
                Pontuacao+=10;
                moeda.sRect.x=567;
                SDL_DestroyTexture(moedao4);
                moeda4.dRect.x=7000;
                moeda4.dRect.y=5000;
            }
            if(dist4<=10 && dipper.dRect.y<=160){
                Pontuacao+=10;
                moeda.sRect.x=567;
                SDL_DestroyTexture(moedao5);
                moeda5.dRect.x=7000;
                moeda5.dRect.y=5000;
            }
             if(dist5<=10 && dipper.dRect.y<=160){
                Pontuacao+=10;
                moeda.sRect.x=567;
                SDL_DestroyTexture(moedao6);
                moeda6.dRect.x=7000;
                moeda6.dRect.y=5000;
            }

            if(distanciaini1<=5 && dipper.dRect.y>=550){
                VidaDipper--;
                dipper.dRect.x=0;
                dipper.dRect.y=600;
            }
            if(distanciaini2<=10 && dipper.dRect.y>=350 && dipper.dRect.y<=400){
                VidaDipper--;
                dipper.dRect.x=0;
                dipper.dRect.y=600;
            }
            if(distanciaini3<=10 && dipper.dRect.y>=100 && dipper.dRect.y<=150){
                VidaDipper--;
                dipper.dRect.x=0;
                dipper.dRect.y=600;
            }
            if(VidaDipper==2){
                vida3.sRect.x=57;
            }
            if(VidaDipper==1){
                vida2.sRect.x=57;
            }


            if(VidaDipper==0){
                menu = 3;
            }


            if(distanciaportal1<=10 && dipper.dRect.y>400 ){
                dipper.dRect.y=375;
            }
            if(distancaiportal2<=10 && dipper.dRect.y<400){
                dipper.dRect.y=150;
                dipper.dRect.x=640;
            }
        }
        if (evento.key.keysym.sym == SDLK_ESCAPE){
            gaming = 0;
        }

        if(menu == 2){
            SDL_RenderClear(render0);
            SDL_RenderCopy(render0, tutorial, NULL, NULL);
            while(SDL_PollEvent(&evento)){
                if(evento.type == SDL_MOUSEMOTION){
                    moveX = evento.motion.x;
                    moveY = evento.motion.y;
                }
                if(evento.type == SDL_MOUSEBUTTONDOWN){
                    if(moveX >= 0 && moveX <= 100 && moveY >= 620 && moveY <= 720 && evento.button.button == SDL_BUTTON_LEFT){
                        menu = 0;
                    }
                }
            }
        }

        if(menu == 3){
            SDL_RenderClear(render0);
            SDL_RenderCopy(render0, lose, NULL, NULL);
            VidaDipper = 3;
            vida2.sRect.x=0;
            vida3.sRect.x=0;
            while(SDL_PollEvent(&evento)){
                if(evento.type == SDL_MOUSEMOTION){
                    moveX = evento.motion.x;
                    moveY = evento.motion.y;
                }
                if(evento.type == SDL_MOUSEBUTTONDOWN){
                    if(moveX >= 0 && moveX <= 640 && moveY >= 0 && moveY <= 720 && evento.button.button == SDL_BUTTON_LEFT){
                        menu = 1;
                        dipper.dRect.x=20;
                        dipper.dRect.y=600;
                    }
                }
                if(evento.type == SDL_MOUSEBUTTONDOWN){
                    if(moveX >= 641 && moveX <= 1280 && moveY >= 0 && moveY <= 720 && evento.button.button == SDL_BUTTON_LEFT){
                        menu = 0;
                    }
                }
            }
        }

        if(menu==10){

            int distanciacav12;
            int distanciaport1,distanciaport2;
            SDL_RenderClear(render0);
            SDL_RenderCopy(render0,fundo_caverna,NULL,NULL);

            SDL_RenderCopy(render0, entrada2, &cavernadies.sRect, &cavernadies.dRect);

            SDL_RenderCopy(render0,platcav,NULL,&pisocav.dRect);
            SDL_RenderCopy(render0,platcav2,NULL,&platcaver.dRect);
            SDL_RenderCopy(render0,platcav,NULL,&platcaver2.dRect);

            SDL_RenderCopy(render0,parede,NULL,&paredechave.dRect);

            SDL_RenderCopy(render0, portal1, &portal.sRect, &portal2.dRect);
            SDL_RenderCopy(render0, portal1, &portal.sRect, &portal3.dRect);
            SDL_RenderCopy(render0, portal1, &portal.sRect, &portal5.dRect);
            SDL_RenderCopy(render0, portal1, &portal.sRect, &portal6.dRect);

            SDL_RenderCopy(render0, inimigo, &ini.sRect, &ini.dRect);
            SDL_RenderCopy(render0, inimigo1, &ini1.sRect, &ini1.dRect);

            SDL_RenderCopy(render0, mabel1, &mabel.sRect, &mabel.dRect);
            SDL_RenderCopy(render0, textura0, &dipper.sRect, &dipper.dRect);

            SDL_RenderCopy(render0, core, &vida.sRect, &vida.dRect);
            SDL_RenderCopy(render0, core1, &vida2.sRect, &vida2.dRect);
            SDL_RenderCopy(render0, core2, &vida3.sRect, &vida3.dRect);





            if(dipper.dRect.y!=600 && dipper.dRect.y!=375 && dipper.dRect.y!=150 ){//gravidade
                    dipper.dRect.y+=10;
            }

            distanciacav12=distancia(dipper.dRect.x,dipper.dRect.y,100,160);

            if(distanciacav12<=10 && dipper.dRect.y<170){
                menu = 1;
                dipper.dRect.y=150;
                dipper.dRect.x=1140;

            }

            distanciaport1= distancia(dipper.dRect.x,dipper.dRect.y,1190,100);
            distanciaport2= distancia(dipper.dRect.x,dipper.dRect.y,5,335);
            distanciamabel = distancia(dipper.dRect.x,dipper.dRect.y,mabel.dRect.x,dipper.dRect.y);
            distanciaini1 = distancia(dipper.dRect.x,dipper.dRect.y,ini.dRect.x,ini.dRect.y);
            distanciaini2 = distancia(dipper.dRect.x,dipper.dRect.y,ini1.dRect.x,ini1.dRect.y);



            if(distanciaport2<=10 && dipper.dRect.y<=380 && dipper.dRect.y>=350){
                dipper.dRect.y=600;
            }

            if(distanciaport1<=10 && dipper.dRect.y<200){
                dipper.dRect.y=365;
            }

            if(distanciamabel<=10 && dipper.dRect.y==600 ){//YOU WIN
                menu = 4;
            }

            if(VidaDipper==2){
                vida3.sRect.x=57;
            }
            if(VidaDipper==1){
                vida2.sRect.x=57;
            }


            if(VidaDipper==0){//You Lose
                menu = 3;
            }
            if(Chave==0){
                if(dipper.dRect.x>690){
                    dipper.dRect.x=689;
                }
            }
            else{
                SDL_DestroyTexture(parede);
            }




            if(distanciaini1<=5 && dipper.dRect.y>=550){
                VidaDipper--;
                dipper.dRect.x=150;
                dipper.dRect.y=150;
            }


            if(distanciaini2<=10 && dipper.dRect.y>=350 && dipper.dRect.y<=400){
                VidaDipper--;
                dipper.dRect.x=150;
                dipper.dRect.y=150;
            }

            if(ini.dRect.x>=-50){
                ini.dRect.x += ini.vel.y;
                ini.sRect.x += 116;
                if(ini.dRect.x<-46){
                    ini.dRect.x = 1280;
                }
                if(ini.sRect.x >= 463){
                    ini.sRect.x = 0;
                }
            }

            if(ini1.dRect.x<=1300){
                ini1.dRect.x += ini1.vel.x;
                ini1.sRect.x += 116;
                if(ini1.dRect.x>1300){
                    ini1.dRect.x = -50;
                }
                if(ini1.sRect.x >= 463){
                    ini1.sRect.x = 0;
                }
            }


            portal.sRect.x+=161;
            if(portal.sRect.x>=638){
                portal.sRect.x = 1;
            }


        }

        if(menu == 11){
            int distanciapor6,distanciaport7,distkey,distanciacav3;
            SDL_RenderClear(render0);
            SDL_RenderCopy(render0,fundo_caverna,NULL,NULL);

            SDL_RenderCopy(render0,entrada2,&ultcav.sRect,&ultcav.dRect);
            SDL_RenderCopy(render0, entrada1, &cavernadire.sRect, &cavernadire.dRect);

            SDL_RenderCopy(render0,platcav,NULL,&pisocav.dRect);
            SDL_RenderCopy(render0,platcav2,NULL,&platcaver.dRect);
            SDL_RenderCopy(render0,platcav,NULL,&platcaver2.dRect);

            SDL_RenderCopy(render0,portal1,&portal.sRect,&portal7.dRect);
            SDL_RenderCopy(render0, portal1, &portal.sRect, &portal2.dRect);
            SDL_RenderCopy(render0, portal1, &portal.sRect, &portal3.dRect);
            SDL_RenderCopy(render0, portal1, &portal.sRect , &portal8.dRect);

            SDL_RenderCopy(render0, key, &Key1.sRect,&Key1.dRect);

            SDL_RenderCopy(render0, inimigo, &ini.sRect, &ini.dRect);
            SDL_RenderCopy(render0, inimigo1, &ini1.sRect, &ini1.dRect);
            SDL_RenderCopy(render0, inimigo2, &ini2.sRect, &ini2.dRect);

            SDL_RenderCopy(render0, textura0, &dipper.sRect, &dipper.dRect);

            SDL_RenderCopy(render0, core, &vida.sRect, &vida.dRect);
            SDL_RenderCopy(render0, core1, &vida2.sRect, &vida2.dRect);
            SDL_RenderCopy(render0, core2, &vida3.sRect, &vida3.dRect);

            if(dipper.dRect.y!=600 && dipper.dRect.y!=375 && dipper.dRect.y!=150 ){//gravidade
                    dipper.dRect.y+=10;
            }

            distanciaini1 = distancia(dipper.dRect.x,dipper.dRect.y,ini.dRect.x,ini.dRect.y);
            distanciaini2 = distancia(dipper.dRect.x,dipper.dRect.y,ini1.dRect.x,ini1.dRect.y);
            distanciaini3 = distancia(dipper.dRect.x,dipper.dRect.y,ini2.dRect.x,ini2.dRect.y);

            distanciapor6= distancia(dipper.dRect.x,dipper.dRect.y,portal7.dRect.x,portal7.dRect.y);
            distanciaport7= distancia(dipper.dRect.x,dipper.dRect.y,portal3.dRect.x,portal3.dRect.y);
            distkey= distancia(dipper.dRect.x,dipper.dRect.y,Key1.dRect.x,Key1.dRect.y);
            distanciacav3= distancia(dipper.dRect.x,dipper.dRect.y,90,600);

            if(distanciacav3<=10 && dipper.dRect.y>=450){
                menu=1;
                dipper.dRect.y=150;
                dipper.dRect.x=120;
            }

            if(distkey<=10 && dipper.dRect.y>=450){
                Chave=1;
                SDL_DestroyTexture(key);
            }

            if(distanciapor6<=10 && dipper.dRect.y<=200){
                dipper.dRect.y=365;
            }

            if(distanciaport7<=10 && dipper.dRect.y<=380 && dipper.dRect.y>=350){
                dipper.dRect.y=600;
            }

            if(distanciaini1<=5 && dipper.dRect.y>=550){
                VidaDipper--;
                dipper.dRect.x=1070;
                dipper.dRect.y=140;
            }
            if(distanciaini2<=10 && dipper.dRect.y>=350 && dipper.dRect.y<=400){
                VidaDipper--;
                dipper.dRect.x=1070;
                dipper.dRect.y=140;
            }
            if(distanciaini3<=10 && dipper.dRect.y>=100 && dipper.dRect.y<=150){
                VidaDipper--;
                dipper.dRect.x=1070;
                dipper.dRect.y=140;
            }






            if(ini.dRect.x>=-50){
                ini.dRect.x += ini.vel.y;
                ini.sRect.x += 116;
                if(ini.dRect.x<-46){
                    ini.dRect.x = 1280;
                }
                if(ini.sRect.x >= 463){
                    ini.sRect.x = 0;
                }
            }
            if(ini1.dRect.x<=1300){
                ini1.dRect.x += ini1.vel.x;
                ini1.sRect.x += 116;
                if(ini1.dRect.x>1300){
                    ini1.dRect.x = -50;
                }
                if(ini1.sRect.x >= 463){
                    ini1.sRect.x = 0;
                }
            }
            if(ini2.dRect.x>=-50){
                ini2.dRect.x += ini2.vel.y;
                ini2.sRect.x += 116;
                if(ini2.dRect.x<-30){
                    ini2.dRect.x = 1130;
                }
                if(ini2.sRect.x >= 463){
                    ini2.sRect.x = 0;
                }
            }
            if(VidaDipper==2){
                vida3.sRect.x=57;
            }
            if(VidaDipper==1){
                vida2.sRect.x=57;
            }


            if(VidaDipper==0){//You Lose
                menu = 3;
            }


            portal.sRect.x+=161;
            if(portal.sRect.x>=638){
                portal.sRect.x = 1;
            }

        }










        if(menu == 4){
            SDL_RenderClear(render0);
            SDL_RenderCopy(render0, win, NULL, NULL);
            VidaDipper = 3;
            vida2.sRect.x=0;
            vida3.sRect.x=0;
            while(SDL_PollEvent(&evento)){
                if(evento.type == SDL_MOUSEMOTION){
                    moveX = evento.motion.x;
                    moveY = evento.motion.y;
                }
                if(evento.type == SDL_MOUSEBUTTONDOWN){
                    if(moveX >= 0 && moveX <= 640 && moveY >= 0 && moveY <= 720 && evento.button.button == SDL_BUTTON_LEFT){
                        VidaDipper = 3;
                        menu = 1;
                    }
                }
                if(evento.type == SDL_MOUSEBUTTONDOWN){
                    if(moveX >= 641 && moveX <= 1280 && moveY >= 0 && moveY <= 720 && evento.button.button == SDL_BUTTON_LEFT){
                        VidaDipper = 3;
                        menu = 0;
                    }
                }
            }
        }

        SDL_RenderPresent(render0);

        while(SDL_PollEvent(&evento)){

            if(dipper.dRect.x>1280-45){
                dipper.dRect.x=1279-45;
            }
            if(dipper.dRect.x<0){
                dipper.dRect.x=1;
            }

            if(evento.type==SDL_QUIT){
                gaming = 0;
            }
            if(evento.type==SDL_KEYUP){
                dipper.sRect.x = 0;
                dipper.sRect.y = 0;
                dipper.sRect.w = 89;
                dipper.sRect.h = 157;
                if(evento.key.keysym.sym==SDLK_UP){
                    if((dipper.dRect.y==600 && dipper.dRect.y!=400) || (dipper.dRect.y==375|| dipper.dRect.y==150)){
                        textura0 = pulo1;
                        for(int k=0;k<9;k++){
                            dipper.dRect.y-=10;
                        }

                        if(evento.key.keysym.sym==SDLK_RIGHT){
                            textura0 = pulo2;
                            for(int rs=0;rs<9;rs++){
                                dipper.dRect.x+=10;
                            }
                        }
                        if(evento.key.keysym.sym==SDLK_LEFT){
                            textura0 = pulo2;
                            for(int rs=0;rs<9;rs++){
                                dipper.dRect.x-=10;
                            }
                        }
                    }
                    textura0 = textura1;
                }
            }
            if(dipper.dRect.y<0){
                dipper.dRect.y=0;
            }
            if(dipper.dRect.y>598){
                dipper.dRect.y=600;
            }
            if(evento.type==SDL_KEYDOWN){
                if (evento.key.keysym.sym == SDLK_ESCAPE){
                    gaming = 0;
                }

                if (evento.key.keysym.sym == SDLK_RIGHT){
                    textura0 = textura1;
                    dipper.dRect.x += dipper.vel.x;
                    dipper.sRect.x += 89;
                    if(dipper.sRect.x >= 356){
                        dipper.sRect.x = 0;
                    }
                }

                if (evento.key.keysym.sym == SDLK_LEFT){
                    textura0 = textura2;
                    dipper.dRect.x += dipper.vel.y;
                    dipper.sRect.x += 89;
                    if(dipper.sRect.x >= 356){
                        dipper.sRect.x = 0;
                    }
                }
            }
        }
        /*Mix_CloseAudio();
        Mix_FreeChunk(som);*/
        SDL_RenderPresent(render0);
        SDL_Delay(70);
    }

    return 0;
}
