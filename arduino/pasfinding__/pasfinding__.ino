void setup() {
  Serial.begin(9600);
}

void loop() {

// départ / arivée
int arive = 2;
int depart = 5;

// les tables
int liaison[2][42] = {{1,1,2,2,2,3,3,3,4,4,4 ,5,5 ,6,6,6,7,7,7,8,8,9,9 ,9 ,10,10,10,10,11,11,11,12,12,13,13,14,14,15,15,15,16,16},
                      {2,6,1,3,7,2,4,8,3,5,10,4,11,1,7,9,2,6,8,3,7,6,10,14,4 ,9 ,11,13,5 ,10,16,15,12,10,12,9 ,15,12,14,16,11,15}};
int lieu[2][17] = {/*{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16},*/
                   {0,0,1,2,3,4,0,1,2,1,3 ,4 ,1 ,3 ,0 ,1 ,4 },
                   {0,0,0,0,0,0,1,1,1,2,2 ,2 ,3 ,3 ,4 ,4 ,4 }};
int OK[2][16] = {{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16},
                 {1,1,1,1,1,1,1,1,1,1 ,1 ,1 ,1 ,1 ,1 ,1 }};  
//table du passfinding
  int table1[5];
  int table2[5];
  int table3[5];
  int table4[5];
  int table5[5];
  int table6[5];
  int fin[100];
  int resultat[6];
  
// variable du passfinding
  int F;
  int Vb = 0;
  int Vc = 0;
  int Vd = 0;
  int Ve = 0;
  
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  int e = 0;
  int f = 0;
  
  int u = 0;
  int v = 0;
  int w = 0;
  int x = 0;
  int y = 0;
  int z = 0;

  int niveau = 10;

// position du point suivant
  int Px;
  int Py;

  int Direction = 0;
  int xAcar = 0;
  int yAcar = 0;

// variable de fin
int FIN_PROGRAME = 0;

// passfinding
    for (a = 0; a < 42; a++){
      if (liaison[0][a] == depart){
        z++;
        table1[z] = liaison[1][a];
        if (table1[z] == arive){
          fin[F] = table1[z];
          fin[F+1] = 0;
          fin[F+2] = 0;
          fin[F+3] = 0;
          fin[F+4] = 0;
          fin[F+5] = 0;
          F += 6;
          niveau = 1;
        }
        for (b = 0; b < 42; b++){
          if (liaison[0][b] == table1[z] && liaison[1][b] != depart){
            y++;
            Vb = liaison[0][b];
            table2[y] = liaison[1][b];
            if (table2[y] == arive && niveau > 2){
              fin[F] = table1[z];
              fin[F+1] = table2[y];
              fin[F+2] = 0;
              fin[F+3] = 0;
              fin[F+4] = 0;
              fin[F+5] = 0;
              F += 6;
              niveau = 2;
            }
            for (c = 0; c < 42; c++){
              if (liaison[0][c] == table2[y] && liaison[1][c] != depart && liaison[1][c] != Vb){
                x++;
                Vc = liaison[0][c];
                table3[x] = liaison[1][c];
                if (table3[x] == arive && niveau > 3){
                  fin[F] = table1[z];
                  fin[F+1] = table2[y];
                  fin[F+2] = table3[x];
                  fin[F+3] = 0;
                  fin[F+4] = 0;
                  fin[F+5] = 0;
                  F += 6;
                  niveau = 3;
                }
                for (d = 0; d < 42; d++){
                  if (liaison[0][d] == table3[x] && liaison[1][d] != depart && liaison[1][d] != Vb && liaison[1][d] != Vc){
                  w++;
                  Vd = liaison[0][d];
                  table4[w] = liaison[1][d];
                  if (table4[w] == arive && niveau > 4){
                    fin[F] = table1[z];
                    fin[F+1] = table2[y];
                    fin[F+2] = table3[x];
                    fin[F+3] = table4[w];
                    fin[F+4] = 0;
                    fin[F+5] = 0;
                    F += 6;
                    niveau = 4;
                  }
                  for (e = 0; e < 42; e++){
                    if (liaison[0][e] == table4[w] && liaison[1][e] != depart && liaison[1][e] != Vb && liaison[1][e] != Vc && liaison[1][e] != Vd){
                    v++;
                    Ve = liaison[0][e];
                    table5[v] = liaison[1][e];
                    if (table5[v] == arive && niveau > 5){
                      fin[F] = table1[z];
                      fin[F+1] = table2[y];
                      fin[F+2] = table3[x];
                      fin[F+3] = table4[w];
                      fin[F+4] = table5[v];
                      fin[F+5] = 0;
                      F += 6;
                      niveau = 5;
                    }
                    for (f = 0; f < 42; f++){
                      if (liaison[0][f] == table5[v] && liaison[1][f] != depart && liaison[1][f] != Vb && liaison[1][f] != Vc && liaison[1][f] != Vd && liaison[1][f] != Ve){
                        u++;
                        liaison[0][f];
                        table6[u] = liaison[1][f];
                        if (table6[u] == arive && niveau > 6){
                          fin[F] = table1[z];
                          fin[F+1] = table2[y];
                          fin[F+2] = table3[x];
                          fin[F+3] = table4[w];
                          fin[F+4] = table5[v];
                          fin[F+5] = table6[u];
                          F += 6;
                          niveau = 6;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}
// programe principal 
while (FIN_PROGRAME == 0){
    
    // si tournant détécter

    // chois de la direction
    for (int N = 6; N > 0; N--){
      if (fin[F-N]!=0){
      Px = lieu[0][fin[F-N]];
      Py = lieu[1][fin[F-N]];
        // Vers le Nord
        if (Direction == 1) {
          // si l'objectif est a gauche
          if (xAcar > Px) {
            // se déplacer à gauche
            TurnLeft();
            Direction = 4;
            // si l'objectif est a droite
          } else if (xAcar < Px) {
            //se déplacer à droite
            TurnRight();
            Direction = 3;
            // si l'objectif est au meme niveau
          } else {
            // si l'objectif est au meme niveau
            if (yAcar ==  Py) FIN_PROGRAME = 1; //arrivé
              // si l'objectif est derrierre
               else if (yAcar < Py){
                // demi-tour
                HalfTurn(); 
                Direction = 1;
              }else {
                //Avancer
                Avancer();
              }     
          }
      
        // Ver le Sud
        }else if ( Direction == 2) {
          //si l'objectif est a droite
          if (xAcar > Px) {
            // se déplacer à droite
            TurnRight();
            Direction = 4;
            
            // si l'objectif est a gauche
          } else if (xAcar < Px) {
            //se déplacer à gauche
            TurnLeft();
            Direction = 3;
          } else {
            // si l'objectif est au meme niveau
            if (yAcar == Py) FIN_PROGRAME = 1; //arrivé
              // si l'objectif est derièrre
              else if (yAcar > Py){
                // demi-tour
                HalfTurn();
                Direction = 1;
              }else {
                //Avancer
                Avancer();
              }
          }
      
      
        // Vers l'Est
        }else if (Direction == 3) {
          //si l'objectif derrière
          if (xAcar > Px) {
            // demi-tour
            HalfTurn();
            Direction = 4;
          }
          // si l'objectif est en face
          else if (xAcar < Px){
             // avancer
             Avancer(); 
          }
          else {
            //si l'objectif est a gauche
            if (yAcar > yDestination) {
              //tourner à gauche
              TurnLeft();
              Direction = 1;
              // si l'objectif est a droite
            } else if (yAcar < yDestination) {
              //tourner à droite
              TurnRight();
              Direction = 2;
              
            }else FIN_PROGRAME = 1;//arrivé
          }
          
          // Vers l'Ouest
        } else if (Direction == 4) {
          //si l'objectif derrière
          if (xAcar > Px) {
            // demi-tour
            HalfTurn();
            Direction = 4;
          }
          // si l'objectif est en face
          else if (xAcar < Px){
             // avancer
             Avancer(); 
          }else{
            // si l'objectif est a droite
            if (yAcar > yDestination) {
              //tourner à droite
              TurnRight();
              Direction = 1;
              //si l'objectif est a gauche
            }else if (yAcar < yDestination) {
              //tourner à gauche
              TurnLeft();
              Direction = 2;
            }else FIN_PROGRAME = 1; //arrivé
          }
        }
        // actualisation de la potion de la voiture
        xAcar = Px;
        yAcar = Py;
      }
    }
  }
}
