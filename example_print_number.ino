/*
// Four Digits Tube Driver(common anode)
// Last-Modified:2019-1-27 13:28:00
// Copyright (C) 2019 SENCOM <sencom1997@outlook.com>
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
const int pin_w[4] = {1,2,3,4};                      // 四位位选(高电平有效)
const int pin_n[8] = {5,6,7,8,9,10,11,12};           // 八位数字产生(低电平有效)

const int n_0[8] = {0,0,0,0,0,0,1,1};                // 0~9 数字
const int n_1[8] = {1,0,0,1,1,1,1,1};
const int n_2[8] = {0,0,1,0,0,1,0,1};
const int n_3[8] = {0,0,0,0,1,1,0,1};
const int n_4[8] = {1,0,0,1,1,0,0,1};
const int n_5[8] = {0,1,0,0,1,0,0,1};
const int n_6[8] = {0,1,0,0,0,0,0,1};
const int n_7[8] = {0,0,0,1,1,1,1,1};
const int n_8[8] = {0,0,0,0,0,0,0,1};
const int n_9[8] = {0,0,0,0,1,0,0,1};

#define SLEEP 500     //延时

void setup() 
{ //初始化
  for(int i = 0; i < 4; i++)
      pinMode(pin_w[i], OUTPUT);
  for(int i = 0; i < 8; i++)
      pinMode(pin_n[i], OUTPUT);
}

void print_a_number(int n)  //输出 一位数字
{
    switch(n)
    {
      case 0:
          for(int i = 0; i < 8; i++)
              digitalWrite(pin_n[i],n_0[i] );break;
      case 1:
          for(int i = 0; i < 8; i++)
              digitalWrite(pin_n[i],n_1[i] );break;
      case 2:    
          for(int i = 0; i < 8; i++)
              digitalWrite(pin_n[i],n_2[i] );break;
      case 3:
          for(int i = 0; i < 8; i++)
              digitalWrite(pin_n[i],n_3[i] );break;
      case 4:
          for(int i = 0; i < 8; i++)
              digitalWrite(pin_n[i],n_4[i] );break;
      case 5:
          for(int i = 0; i < 8; i++)
              digitalWrite(pin_n[i],n_5[i] );break;
      case 6:
          for(int i = 0; i < 8; i++)
              digitalWrite(pin_n[i],n_6[i] );break;
      case 7:
          for(int i = 0; i < 8; i++)
              digitalWrite(pin_n[i],n_7[i] );break;
      case 8:
          for(int i = 0; i < 8; i++)
              digitalWrite(pin_n[i],n_8[i] );break;
      case 9:
          for(int i = 0; i < 8; i++)
              digitalWrite(pin_n[i],n_9[i] );break;
    }
}
void print_number(int nums)   //输出一个数字（最多四位）
{
  int num[4];
  for(int i = 3; i >= 0; i--)
  {
      num[i] = nums % 10;
      nums  /= 10; 
  }
  for(int i = 0; i < 4; i++)
  {
      digitalWrite(pin_w[i], HIGH);
      for(int k = 0; k < 4; k++)
      {
        if(k != i)
            digitalWrite(pin_w[i], LOW);
      }
      print_a_number(num[i]);
  }
}
void tube_dance(int spd)
{
  for(int i = 0 ;i < 4; i++)    //四位同输出
  {
      digitalWrite(pin_w[i], HIGH);
  }
  digitalWrite(pin_n[6],HIGH);     //禁用h 和 dp
  digitalWrite(pin_n[7],HIGH);
  
  for(int i = 0; i < 6; i++)
  {
        for(int j = 0; j < 6; j++)
        {
              if(j == i)
                  digitalWrite(pin_n[j],LOW);
              else
                  digitalWrite(pin_n[j],HIGH);
        }
        delay(spd);
  }
  
}
void loop()
{
    print_number(2019);
}
