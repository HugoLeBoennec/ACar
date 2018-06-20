void setup() {
  Serial.begin(9600);
}

void afficher(int fin[6],int F){
   Serial.println("chemin : ");
    if (fin[F]!=0) Serial.println(fin[F]);
    if (fin[F+1]!=0) Serial.println(fin[F+1]);
    if (fin[F+2]!=0) Serial.println(fin[F+2]);
    if (fin[F+3]!=0) Serial.println(fin[F+3]);
    if (fin[F+4]!=0) Serial.println(fin[F+4]);
    if (fin[F+5]!=0)  Serial.println(fin[F+5]);
}

void loop() {
    int arive = 2;
int depart = 5;

int liaison[2][42] = {{1,1,2,2,2,3,3,3,4,4,4 ,5,5 ,6,6,6,7,7,7,8,8,9,9 ,9 ,10,10,10,10,11,11,11,12,12,13,13,14,14,15,15,15,16,16},
                      {2,6,1,3,7,2,4,8,3,5,10,4,11,1,7,9,2,6,8,3,7,6,10,14,4 ,9 ,11,13,5 ,10,16,15,12,10,12,9 ,15,12,14,16,11,15}};
int lieu[3][16] = {{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16},
                   {0,1,2,3,4,0,1,2,1,3,4,1,3,0,1,4},
                   {0,0,0,0,0,1,1,1,2,2,2,3,3,4,4,4}};
int OK[2][16] = {{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16},
                 {1,1,1,1,1,1,1,1,1,1 ,1 ,1 ,1 ,1 ,1 ,1 }};
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
  
  int table1[5];
  int table2[5];
  int table3[5];
  int table4[5];
  int table5[5];
  int table6[5];
  int fin[100];
  int resultat[6];

    Serial.println("start");
    for (a = 0; a < 42; a++){
      if (liaison[0][a] == depart){
        z++;
        table1[z] = liaison[1][a];
                        Serial.print("a ) ");
                        Serial.print(liaison[0][a]);
                        Serial.print(" -> ");
                        Serial.println(table1[z]);
        if (table1[z] == arive){
          fin[F] = table1[z];
          fin[F+1] = 0;
          fin[F+2] = 0;
          fin[F+3] = 0;
          fin[F+4] = 0;
          fin[F+5] = 0;
          afficher(fin,F);
          F += 6;
          niveau = 1;
        }
        for (b = 0; b < 42; b++){
          if (liaison[0][b] == table1[z] && liaison[1][b] != depart){
            y++;
            Vb = liaison[0][b];
            table2[y] = liaison[1][b];
                            Serial.print("b ) ");
                            Serial.print(liaison[0][b]);
                            Serial.print(" -> ");
                             Serial.println(table2[y]);
            if (table2[y] == arive && niveau > 2){
              fin[F] = table1[z];
              fin[F+1] = table2[y];
              fin[F+2] = 0;
              fin[F+3] = 0;
              fin[F+4] = 0;
              fin[F+5] = 0;
              afficher(fin,F);
              F += 6;
              niveau = 2;
            }
            for (c = 0; c < 42; c++){
              if (liaison[0][c] == table2[y] && liaison[1][c] != depart && liaison[1][c] != Vb){
                x++;
                Vc = liaison[0][c];
                table3[x] = liaison[1][c];
                                Serial.print("c ) ");
                                Serial.print(liaison[0][c]);
                                Serial.print(" -> ");
                                 Serial.println(table3[x]);
                if (table3[x] == arive && niveau > 3){
                  fin[F] = table1[z];
                  fin[F+1] = table2[y];
                  fin[F+2] = table3[x];
                  fin[F+3] = 0;
                  fin[F+4] = 0;
                  fin[F+5] = 0;
                  afficher(fin,F);
                  F += 6;
                  niveau = 3;
                }
                for (d = 0; d < 42; d++){
                  if (liaison[0][d] == table3[x] && liaison[1][d] != depart && liaison[1][d] != Vb && liaison[1][d] != Vc){
                  w++;
                  Vd = liaison[0][d];
                  table4[w] = liaison[1][d];
                                          Serial.print("d ) ");
                                          Serial.print(liaison[0][d]);
                                          Serial.print(" -> ");
                                          Serial.println(table4[w]);

                  if (table4[w] == arive && niveau > 4){
                    fin[F] = table1[z];
                    fin[F+1] = table2[y];
                    fin[F+2] = table3[x];
                    fin[F+3] = table4[w];
                    fin[F+4] = 0;
                    fin[F+5] = 0;
                    afficher(fin,F);
                    F += 6;
                    niveau = 4;
                  }
                  for (e = 0; e < 42; e++){
                    if (liaison[0][e] == table4[w] && liaison[1][e] != depart && liaison[1][e] != Vb && liaison[1][e] != Vc && liaison[1][e] != Vd){
                    v++;
                    Ve = liaison[0][e];
                    table5[v] = liaison[1][e];
                                            Serial.print("e ) ");
                                            Serial.print(liaison[0][e]);
                                            Serial.print(" -> ");
                                            Serial.println(table5[v]);

                    if (table5[v] == arive && niveau > 5){
                      fin[F] = table1[z];
                      fin[F+1] = table2[y];
                      fin[F+2] = table3[x];
                      fin[F+3] = table4[w];
                      fin[F+4] = table5[v];
                      fin[F+5] = 0;
                      afficher(fin,F);
                      F += 6;
                      niveau = 5;
                    }
                    for (f = 0; f < 42; f++){
                      if (liaison[0][f] == table5[v] && liaison[1][f] != depart && liaison[1][f] != Vb && liaison[1][f] != Vc && liaison[1][f] != Vd && liaison[1][f] != Ve){
                        u++;
                        liaison[0][f];
                        table6[u] = liaison[1][f];
                                                Serial.print("f ) ");
                                                Serial.print(liaison[0][f]);
                                                Serial.print(" -> ");
                                                Serial.println(table6[u]);

                        if (table6[u] == arive && niveau > 6){
                          fin[F] = table1[z];
                          fin[F+1] = table2[y];
                          fin[F+2] = table3[x];
                          fin[F+3] = table4[w];
                          fin[F+4] = table5[v];
                          fin[F+5] = table6[u];
                          afficher(fin,F);
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

    Serial.println("chemin : ");
    if (fin[F-6]!=0) Serial.println(fin[F-6]);
    if (fin[F-5]!=0) Serial.println(fin[F-5]);
    if (fin[F-4]!=0) Serial.println(fin[F-4]);
    if (fin[F-3]!=0) Serial.println(fin[F-3]);
    if (fin[F-2]!=0) Serial.println(fin[F-2]);
    if (fin[F-1]!=0)  Serial.println(fin[F-1]);
    delay(1000000);
}


