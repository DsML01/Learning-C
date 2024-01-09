    #include <stdio.h>
    int viagem(int dias,int moedas,int x,int y,int royaume) {
        char direction;
        if (dias==0) {
            return moedas;
        }
        else {
            scanf(" %c", &direction);
            if (x==0 && y==0) {
                if (direction=='C'){
                    return viagem(dias-1,moedas,x,y+1,2);
                }
                else {
                    return viagem(dias-1,moedas,x+1,y,1);
                }
            }
            else {
                if (direction=='C'){
                    if (x==y) {
                        if (royaume==1) {
                            return viagem(dias-1,moedas+1,x,y+1,2);
                        }
                        else {
                            return viagem(dias-1,moedas,x,y+1,royaume);
                        }
                    }
                    else {
                        return viagem(dias-1,moedas,x,y+1,royaume);
                    }
                }
                else {
                    if (x==y) {
                        if (royaume==1) {
                            return viagem(dias-1,moedas,x+1,y,royaume);
                        } 
                        else {
                            return viagem(dias-1, moedas+1,x+1,y,1);
                        }
                    }
                    else {
                        return viagem(dias-1,moedas,x+1,y,royaume);
                    }

                }
            }
        }

    }

    int main () {
        int dias,royaume;
        scanf ("%d", &dias);
        printf ("%d",viagem (dias,0,0,0,royaume));

        return 0;
    }