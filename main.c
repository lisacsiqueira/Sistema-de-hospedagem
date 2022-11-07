/*
Universidade Estadual da Paraíba - UEPB

Resumo: Nosso grupo criou um Sistema de Hospedagem para Hotel. Nesse sistema o usuário poderá apreciar o catálogo de suítes disponíveis, criar uma conta, fazer reserva, cancelar a reserva e aproveitar as nossas promoções imperdíveis. Tudo isso de maneira rápida e fácil. :D

GRUPO 04 - TEMA 02
    - Lisa Asheley Costa Siqueira
    - Rennan Fernandes da Silva
    - Shara Isabell Alves de Oliveira
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define AMARELO "\x1b[93m"
#define AZUL "\x1b[34m"
#define VERDE "\x1b[32m"
#define ROXO "\x1b[95m"
#define VERMELHO "\x1b[31m"
#define CIANO "\x1b[96m"
#define RESET "\x1b[0m"

// Menu
int main() {
  // Estrutura que pega o horário atual
  struct tm *data_hora_atual;     
    time_t segundos;
    time(&segundos);   
    data_hora_atual = localtime(&segundos);
  
  int op, senha, senha_confirmacao, tentativas = 1, i, comeco_dia, dias, numero_pessoas, quarto_escolhido, quant_quartos, quarto1, quarto2, quarto3, opt, eh_valido = 0, promocao, num_sorteio;
  float valor_quarto = 0, valor_quarto2 = 0, valor_quarto3 = 0, total = 0, desconto;
  char email[80], nome_completo[80], cpf[15], data_nascimento[15], email_confirmacao[80];
  FILE *emailzin;

  printf("                  ▄▀▄     ▄▀▄\n                 ▄█░░▀▀▀▀▀░░█▄\n             ▄▄──█░░░░░░░░░░░█──▄▄\n╔═══════════█▄▄█─█░░▀░░┬░░▀░░█─█▄▄█═══════════╗\n║                   TUTORIAL                  ║\n╚═════════════════════════════════════════════╝                   \n╔═════════════════════════════════════════════╗\n║              \t\t\t\t\t\t\t\t  ║\n║    Olá, para melhor experiência no nosso    ║\n║      sistema siga os seguintes passos:      ║\n║                                             ║\n║ 1)  Crie uma conta.                         ║\n║ 2)  Acesse nosso catálogo de suítes e       ║\n║     escolha a de sua preferência.           ║\n║ 3)  Realize a sua Reserva.                  ║\n║ 4)  Acessar conta serve para checar         ║\n║     detalhes sobre sua hospedagem.          ║\n║                                             ║\n║            Aproveite sua Estadia            ║\n╚═════════════════════════════════════════════╝\n\n");
  
  printf(AMARELO " ʕ•́ᴥ•̀ʔっBEM-VINDO(A) AO NOSSO HOTEL!\n\n" RESET);
  do {
    printf(AMARELO "❣---------MENU---------❣\n" RESET);
    printf(AZUL " 1 - Criar conta\n 2 - Acessar Catálogo\n 3 - Realizar reserva\n 4 - Acessar conta\n 5 - Sair\n\n -> " RESET);
    scanf("%d", &op);
    sleep(1);

    switch (op) {
      
      case 1:
        printf(AZUL "\n\n（っ＾▿＾） Informe o endereço de e-mail:\n☺ " RESET);
        scanf("%s", email);
        printf(AZUL "Informe uma senha númerica:\n☺ " RESET);
        scanf("%d", &senha);
        printf(AZUL "CPF:\n☺ " RESET);
        scanf("%s", cpf);
        printf(AZUL "Data de nascimento:\n☺ " RESET);
        scanf("%s", data_nascimento);
        break;
      
      case 2:
        printf("\n╔══════════════════════════════════════════╗");
        printf("\n║      Catálogo de Preços das Suítes       ║");
        printf("\n╚══════════════════════════════════════════╝");
        printf("\n╔══════════════════════════════════════════╗");
        printf("\n║                                          ║");
        printf("\n║ 🛏️  Quartos de solteiro: R$ 200,00        ║");
        printf("\n║ 🛏️  Quartos de duplo solteiro: R$ 350,00  ║");
        printf("\n║ 🛏️  Quartos Triplos: R$ 650,00            ║");
        printf("\n║ 🛏️  Quartos de casal: R$ 500,00           ║");
        printf("\n║                                          ║");
        printf("\n╚══════════════════════════════════════════╝");
        break;
      

      case 3:
       printf(VERDE "\n✨MÊS DE NOVEMBRO!✨" RESET);
       printf(VERDE "\n\ndom seg ter qua qui sex sáb\n\t\t 1   2   3   4   5\n 6   7   8   9  10  11  12\n13  14  15  16  17  18  19\n20  21  22  23  24  25  26\n27  28  29  30" RESET); 
        do {
          printf(VERDE"\n\nInforme o dia do check-in:\n☺ "RESET);
          scanf("%d", &comeco_dia);
          printf(VERDE "Quantos dias você deseja ficar? \n☺ " RESET);
          scanf("%d", &dias);
          if (comeco_dia + dias > 30){
            printf(VERMELHO "\n(╥_╥) Não há vagas\nTente novamente!" RESET);
          }
        } while (comeco_dia + dias > 30);
        
       sleep(1);
       printf("\n---------------------------------------------------------");
       printf("\n|Para melhor experiência do cliente,               \t\t|\n|cada usuário só poderá levar até 3 pessoas             |");
       printf("\n---------------------------------------------------------");
       printf("\n🛏️  Quartos de solteiro: Comportam apenas uma pessoa.");
       printf("\n🛏️  Quartos de duplo solteiro: Comportam duas pessoas.");
       printf("\n🛏️  Quartos de casal: Comportam duas pessoas.");
       printf("\n🛏️  Quartos triplos: Comportam três pessoas.");
       printf("\n---------------------------------------------------------\n\n");
       sleep(1);
        
        do{
          printf(VERDE "Informe o número de pessoas: \n☺ " RESET);
          scanf("%d", &numero_pessoas);
        } while (numero_pessoas > 3);
        
        // Seleção de quartos é mostrada de acordo com o que o usuário digitou
        if (numero_pessoas == 1){
          printf("\n\n🛏️ Quartos de solteiro disponíveis: \n101\t103\t105");
        } else if (numero_pessoas == 2){
          printf("\n🛏️ Quartos de duplo solteiro disponíveis: \n102\t104\t106\n");
          printf("\n\n🛏️ Quartos de casal disponíveis: \n201\t205\t206\n");
        } else if (numero_pessoas == 3){
          printf(VERDE "Deseja quantos quartos?\n☺ " RESET);
          scanf("%d", &quant_quartos);
        } if(quant_quartos == 3 || quant_quartos == 2){
          printf("\n\n🛏️ Quartos de solteiro disponíveis: \n101\t103\t105\n");
        } if(quant_quartos == 2){
          printf("\n\n🛏️ Quartos de duplo solteiro disponíveis: \n102\t104\t106\n");
          printf("\n\n🛏️ Quartos de casal disponíveis: \n201\t205\t206\n");
        } else if(quant_quartos == 1){
          printf("\n\n🛏️ Quartos para três pessoas disponíveis:\n301\t302\n");
        }
        
        // Escolha de quarto, valores e validação
        do{
          if(numero_pessoas == 1 || numero_pessoas == 2 || quant_quartos == 1){
          printf(VERDE "\n\nInforme o quarto desejado:\n☺ " RESET);
          scanf("%d", &quarto1);
          } else if(quant_quartos == 2){
            printf(VERDE "\n\nInforme os quartos que deseja:\n☺ " RESET);
            scanf("%d%d", &quarto1, &quarto2);
          } else if(quant_quartos == 3){
            printf(VERDE "\n\nInforme os quartos que deseja:\n☺ " RESET);
            scanf("%d%d%d", &quarto1, &quarto2, &quarto3);
          }
  
        if (quarto1 == 101 || quarto1 == 103 || quarto1 == 105){
          valor_quarto = 200;
          eh_valido = 1;
        } else if (quarto1 == 102 || quarto1 == 104 || quarto1 == 105){
          valor_quarto = 350;
          eh_valido = 1;
        } else if (quarto1 == 201 || quarto1 == 205 || quarto1 == 206){
          valor_quarto = 500;
          eh_valido = 1;
        } else if (quarto1 == 301 || quarto1 == 302){
          valor_quarto = 650;
          eh_valido = 1;
        } if (quarto2 == 101 || quarto2 == 103 || quarto2 == 105){
          valor_quarto2 = 200;
          eh_valido = 1;
        } else if (quarto2 == 102 || quarto2 == 104 || quarto2 == 105){
          valor_quarto2 = 350;
          eh_valido = 1;
        } else if (quarto2 == 201 || quarto2 == 205 || quarto2 == 206){
          valor_quarto2 = 500;
          eh_valido = 1;
        } if (quarto3 == 101 || quarto3 == 103 || quarto3 == 105){
          valor_quarto3 = 200;
          eh_valido = 1;
        }
        //Total ao juntar com dias que irá ficar
        if (eh_valido == 0){
          printf(VERMELHO "\n(ಠ_ಠ) Opção inválida" RESET);
        }
        else{
          if (numero_pessoas == 1 || numero_pessoas == 2){
          total = valor_quarto * dias;
        } else if(numero_pessoas == 3){
            if(quant_quartos == 1){
            total = valor_quarto * dias;
          } else if(quant_quartos == 2){
            total = (valor_quarto + valor_quarto2) * dias;
          } else if(quant_quartos == 3){
            total = (valor_quarto + valor_quarto2 + valor_quarto3) * dias;
          }
        } 
        sleep(1);

        // Promoções
        printf("Deseja concorrer até 30%% de desconto\n0: Não \n1: Sim [0/1]\n☺ ");
        scanf("%d", &promocao);
        if (promocao == 0){
          printf(VERDE "\n$_$ O valor total é de: R$ %.2f" RESET, total);
        } else if(promocao == 1){
          printf("Escolha um número de 1 a 10 para sortearmos uma promoção exclusiva para você: ");
          scanf("%d", &num_sorteio);
          switch(num_sorteio){
            case 1: 
              printf("Ahh, não foi dessa vez... ಥ_ಥ");
            break;
            case 2:
              desconto = total * 0.15;
              total = total - desconto;
              printf("\nDesconto de 15%%: %.2f. O total a pagar é: %.2f ",  desconto, total);
              break;
            case 3: 
              desconto = total * 0.20;
              total = total - desconto;
              printf("\nDesconto de 20%%: %.2f. O total a pagar é: %.2f ", desconto, total);
              break;
            case 4:
              printf("Ahh, não foi dessa vez... ಥ_ಥ");
              break;
            case 5: 
              desconto = total * 0.30;
              total = total - desconto;
              printf("\nDesconto de 30%%: %.2f. O total a pagar é: %.2f ", desconto, total);
              break;
            case 6: 
              printf("Ahh, não foi dessa vez... ಥ_ಥ");
              break;
            case 7: 
              printf("Ahh, não foi dessa vez... ಥ_ಥ");
              break;
            case 8: 
              desconto = total * 0.25;
              total = total - desconto;
              printf("\nDesconto de 25%%: %.2f. O total a pagar é: %.2f ", desconto, total);
              break;
            case 9: 
              printf("Ahh, não foi dessa vez... ಥ_ಥ");
              break;
            case 10: 
              desconto = total * 0.05;
              total = total - desconto;
              printf("\nDesconto de 5%%: %.2f. O total a pagar é: %.2f ", desconto, total);
              
              break;
            default:
              printf(VERMELHO "Entrada inválida!" RESET);
          }
        }
          
          else{
            printf("\nAhh, perdeu a oportunidade de ganhar um descontão!  \n\n");
            printf(VERDE "\n$_$ O valor total é de: R$ %.2f" RESET, total);
            }
          
        }
        } while(eh_valido == 0);
          
        break;

// Acessar conta
      case 4:
        while (tentativas <= 3) {
          printf(ROXO "\n\n(っ◕‿◕)っ Informe o seu e-mail:\n☺ " RESET);
          scanf("%s", email_confirmacao);
          printf(ROXO "Informe sua senha numérica:\n☺ " RESET);
          scanf("%d", &senha_confirmacao);
  
          if (strcmp(email, email_confirmacao) == 0 && senha == senha_confirmacao) {
            printf(ROXO "\n\nAcessando conta...\n" RESET);
            tentativas = 4;
  
            sleep(1);
            printf("\n\nSeja bem-vindo(a), %s!", email);

          // Bilhete de Reserva
          do{
            sleep(1);
             printf("\n\nv(=∩_∩=)ﾌ O que deseja fazer?");
             printf(CIANO "\n\n❣---------MENU---------❣\n" RESET);
             printf(AMARELO " 1 - Comprovante de Reserva\n 2 - Cancelamento de Reserva\n 3 - Sair\n\n -> " RESET);
             scanf("%d", &opt);
            switch(opt){
              case 1:
                printf("-----------------------------------");
                printf("\n| 🏩 Bem-vindo ao nosso Hotel! 🏩 |");
                printf("\n-----------------------------------");
                printf("\n|  🌅                             |");
                printf("\n| Horário de Reserva: %d:%d:%d     |", data_hora_atual->tm_hour - 3, data_hora_atual->tm_min, data_hora_atual->tm_sec);
                printf("\n| Data de Reserva: %d / 11 / 2022  |", data_hora_atual->tm_mday);
                printf("\n|                                 |");
                printf("\n| Data de Check-in: %d / 11 / 2022 |", comeco_dia);
                printf("\n|                                 |");
                printf("\n| Data de Check-out:%d / 11 / 2022 |", comeco_dia + dias - 1);
                printf("\n|_________________________________|");
                printf("\n  Quarto(s) Reservado(s):         ");

// Lógica para selecionar os quartos escolhidos              
                if (numero_pessoas == 1 || numero_pessoas == 2){
                      printf("\n %d.................R$ %.2f", quarto1, valor_quarto);
                      printf("\n Total: R$ %.2f", total);
                    } else if(numero_pessoas == 3){
                        if(quant_quartos == 1){
                        printf("\n %d.................R$ %.2f", quarto1, valor_quarto);
                        printf("\n Total: R$ %.2f", total);
                      } else if(quant_quartos == 2){
                        printf("\n %d.................R$ %.2f", quarto1, valor_quarto);
                        printf("\n %d.................R$ %.2f", quarto2, valor_quarto2);
                        printf("\n Total: R$ %.2f", total);
                      } else if(quant_quartos == 3){
                        printf("\n %d.................R$ %.2f", quarto1, valor_quarto);
                        printf("\n %d.................R$ %.2f", quarto2, valor_quarto2);
                        printf("\n %d.................R$ %.2f",quarto3, valor_quarto3);
                        printf("\n Total: R$ %.2f", total);
                      }
                    }
                        printf("\n|¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨|");
                        printf("\n|         █║▌│█│║▌║││█║▌║▌║       |");
                        printf("\n|                                 |");
                        printf("\n|🛎️ Agradecemos pela preferência!🧳|");
                        printf("\n|                              🏖️  |");
                        printf("\n|_________________________________|");
  
                        printf("\n\nTambém aceitamos pagamento por meio de Pix!");
                        printf("\n\n▄▄▄▄▄▄▄     ▄▄    ▄▄▄  ▄  ▄▄▄▄▄▄▄");
                        printf("\n█ ▄▄▄ █ ▀ ▀ ▄ ▀█▀▀▀  █▄▄▄ █ ▄▄▄ █");
                        printf("\n█ ███ █ ▀█▀██▀ ▀▄▀ ▄ ▄▀▄▀ █ ███ █");
                        printf("\n█▄▄▄▄▄█ █▀▄ █ ▄▀▄▀█ █▀▄ █ █▄▄▄▄▄█");
                        printf("\n▄▄▄▄▄ ▄▄▄█▀█▄ ▄▄▄▄▀▄▀▀▀█▄▄ ▄ ▄ ▄");
                        printf("\n▄▀▀▀▀▀▄▀█ █▀ ▀▄▄█▀█▀██ ▀▄ ▀▄ ▀█▄▀");
                        printf("\n▄▀  ▀▄▄▄▀▄▄ █▄▄█ ▄  ▀▀▀██▀ ▄█▀▀▀ ");
                        printf("\n▄▀▀▀▀▀▄▄▀▄▄▀▄▀ ▄▀ █▀██ █▀ ▀  ██▄▀");
                        printf("\n█▄▀▀▄▀▄▀▀▀ █▄▄█▀ ▄ ▀▀▀ ▀█▄ ▄▄▀▀ ▀");
                        printf("\n▀█▀▀ ▄▄▀▄▄ ▀▄▄▀▄█ ▀▀██ ▄▄▀▀▄ ▄▀█▀");
                        printf("\n▀██▄ ▄▄▀▄▀██▄▄█▄▄▄▀  ▀ ▀▀▄ ▀▄▀▀█▀");
                        printf("\n█▀█ ▀▄▄ ██ ▀   █▀ █▀██ ▀ ▀▀▄ ██▄▀");
                        printf("\n █  █▄█▄▀ ▀▄ ▄▄▀█ ▄▄▀▄▀  ▄▄██▄▀▀▀ ");
                        printf("\n▄▄▄▄▄▄▄ █▄▀▀▄  ▄  █▀▀▄ ▄█ ▄ ██▄▄ ");
                        printf("\n█ ▄▄▄ █ ▄█▀▀▀▄▄▄▄▄▀█▀█▄▀█▄▄▄█▀▀▀█");
                        printf("\n█ ███ █ █ ▀ ▄ ▄▄█ ▄▀█▄▄▄▄▀▄█▀█ ▄ ");
                        printf("\n█▄▄▄▄▄█ █▀█ █▄▀ ▀▄▀ ▀▀█▄▄█ ▄▀█▀▄ ");
                        
                break;
              
// E-mail de cancelamento
              case 2: 
                emailzin = fopen("📧 E-mail.txt", "w");
                if(emailzin == NULL){
                  printf(VERMELHO "(×̯×) ERROR!" RESET);
                } else{
                  printf(CIANO"\n\nEnviaremos pelo e-mail o comprovante de cancelamento. o(╥﹏╥)o\n\nEspero que você tenha outras oportunidades de aproveitar seu \ntempo livre em nosso hotel. (◕︵◕)\n"RESET);
                  fprintf(emailzin,"Pedido de Cancelamento Recebido!\n\nAqui está o seu comprovante de cancelamento, %s!\n\n", email);
                  fprintf(emailzin,"╔═════════════════════════════════╗");
                  fprintf(emailzin,"\n║ 🏩  Cancelamento de Reserva  🏩 ║");
                  fprintf(emailzin,"\n╚═════════════════════════════════╝");
                  fprintf(emailzin,"\n╔═════════════════════════════════╗");
                  fprintf(emailzin,"\n║  Comprovante de cancelamento do ║");
                  fprintf(emailzin,"\n║     cliente portador do CPF     ║");
                  fprintf(emailzin,"\n║         %s          ║", cpf);
                  fprintf(emailzin, "\n║     Horário de Cancelamento:    ║");
                  fprintf(emailzin, "\n║            %d:%d:%d             ║", data_hora_atual->tm_hour - 3, data_hora_atual->tm_min, data_hora_atual->tm_sec);
        
                  fprintf(emailzin,"\n║                                 ║");
                  fprintf(emailzin,"\n╚═════════════════════════════════╝");
                }
                fclose(emailzin);
                
                break;
              
            }
          } while(opt != 3);
            } else {
            if (tentativas == 3) {
              printf(VERMELHO "\n\n(×̯×) ERROR!\n" RESET);
              tentativas = 4;
            } else {
              printf(VERMELHO "\n\nE-mail ou senha incorretos!\nPor favor, tente novamente.\n" RESET);
              tentativas++;
            }
          }
        }
        break;
      
    }
    printf("\n\n");
  } while (op != 5);

  return 0;
}