void setup() {
  Serial.begin(9600);
}

void loop() {
int arive = 3;
int depart = 1;
  
int liaison[42][42] = {{1,1,2,2,2,3,3,3,4,4,4,5,5,6,6,6,7,7,7,8,8,9,9,9,10,10,10,10,11,11,11,12,12,13,13,14,14,15,15,15,16,16},{2,6,1,3,7,2,4,8,3,5,10,4,11,1,7,9,2,6,8,3,7,6,10,14,4,9,11,13,5,10,16,15,12,10,12,9,15,12,14,16,11,15}};
int lieu[16][16][16] = {{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16},{0,1,2,3,4,0,1,2,1,3,4,1,3,0,1,4},{0,0,0,0,0,1,1,1,2,2,2,3,3,4,4,4}};
int OK[16][16] = {{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
 
  int fin = 0;
  int FIN = 0;
  int u = 0;
  int v = 0;
  int w = 0;
  int x = 0;
  int y = 0;
  int z = 0;
  int table1[4];
  int table2[4];
  int table3[4];
  int table4[4];
  int table5[4];
  int table6[4];

  while (FIN == 0){
    Serial.println("machin");
    for (int a = 1; a < 16; a++){
      Serial.println("truc");
      if (liaison[0][a] == depart){
        table1[z] = liaison[0][a];
        if (table1[z] == arive){
          FIN = 1;
          fin = 1;
        }
        z++;
        for (int b = 1; b < 16; b++){
          if (liaison[0][b] == table1[z]){
            table2[y] = liaison[0][b];
            if (table2[y] == arive){
//              FIN = 1;
              fin = 1;
            }
            y++;
            for (int c = 1; c < 16; c++){
              if (liaison[0][c] == table2[y]){
                table3[x] = liaison[0][c];
                if (table3[x] == arive){
                  FIN = 1;
                  fin = 3;
                }
                x++;
                for (int d = 1; d < 16; d++){
                  if (liaison[0][d] == table3[x]){
                  table4[w] = liaison[0][d];
                  if (table4[w] == arive){
                    FIN = 1;
                    fin = 4;
                  }
                  w++;
                  for (int e = 1; e < 16; c++){
                    if (liaison[0][e] == table4[w]){
                    table5[v] = liaison[0][e];
                    if (table5[v] == arive){
                      FIN = 1;
                      fin = 5;
                    }
                    v++;
                    for (int f = 1; f < 16; c++){
                      if (liaison[0][v] == table4[v]){
                        table6[u] = liaison[0][f];
                        if (table6[u] == arive){
                          FIN = 1;
                          fin = 6;
                        }
                        u++;
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
    Serial.print("chemin : ");
    if (fin > 0) Serial.println(table1[z]);
    if (fin > 1) Serial.println(table2[y]);
    if (fin > 2) Serial.println(table3[x]);
    if (fin > 3) Serial.println(table4[w]);
    if (fin > 4) Serial.println(table5[v]);
    if (fin > 5) Serial.println(table6[u]);
  delay(1000);
}

