/*
  Tarefa EmbarcaTech - Programação em sistemas embarcados utilizando linguagem C 
  Aluno: Devid Henrique Pereira dos Santos
  Matrícula: TIC370100380
  Polo: Vitória da Conquista

  Vídeo da demonstração no Youtube: https://youtu.be/rnZYiWdYdX0
  Projeto Wokwi: https://wokwi.com/projects/419638840277903361
  Github: https://github.com/Dev1dH/TarefasEmbarcaTech
*/

#include "pico/stdlib.h"
#define led_pin_red 13 //definindo o pino do LED na raspberry pi pico w

//define as constantes de tempo
int tempo_ponto = 200;            //tempo em ms do LED para a letra S
int tempo_traco = 800;            //tempo em ms do LED para a letra O
int tempo_gap = 125;              //o intervalo entre pontos e traços dentro de uma mesma letra
int tempo_intervalo_letras = 250; //o intervalo entre letras
int tempo_intervalo = 3000;       //tempo em ms para o LED reiniciar o código morse

int main() {
    gpio_init(led_pin_red);
    gpio_set_dir(led_pin_red, GPIO_OUT);
 
     while (true) 
     {
        for(int i=0; i<3 ; i++){
        gpio_put(led_pin_red, true); //LED fica ligado por 0,2s
          sleep_ms(tempo_ponto);
        gpio_put(led_pin_red, false);
          sleep_ms(tempo_gap); //LED espera 0,125s para reiniciar o loop da mesma letra
    }
      
      sleep_ms(tempo_intervalo_letras); //intervalo de 0,250s entre as letras
      
      for(int j=3; j<6 ; j++){
        gpio_put(led_pin_red, true);//LED fica ligado por 0,8s
          sleep_ms(tempo_traco);
        gpio_put(led_pin_red, false);
          sleep_ms(tempo_gap);//LED espera 0,125s para reiniciar o loop da mesma letra
      }
      
      sleep_ms(tempo_intervalo_letras); //intervalo de 0,250s entre as letras
      
      for(int s=5; s<8 ; s++){
        gpio_put(led_pin_red, true); //LED fica ligado por 0,2s
          sleep_ms(tempo_ponto);
        gpio_put(led_pin_red, false);
          sleep_ms(tempo_gap); //LED espera 0,125s para reiniciar o loop da mesma letra
      }

    sleep_ms(3000); //aguarda 3s para reiniciar o loop
    }
}