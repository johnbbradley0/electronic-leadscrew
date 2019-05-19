
#include <iostream>
#include <iomanip>
#include <math.h>
 
using namespace std;

struct Tpi
{
   int encRng;
   int stpRng;
   int adjCnt;
};

enum tpiName {
i160,  i120,  i90,  i80,  i72,  i64,  i56,  i48,  i44,  i40,  i36,  i32,  i28,  i24,  i20,  i18,  i16,  i14,  i13,  i12,  i11,  i10,  i9,  i7,  i6,  m725,  m635,  m564,  m508,  m423,  m362,  m338,  m317,  m282,  m254,  m203,  m169,  m145,  m127,  m101,  m84,  m72,  m63,  m56,  m50,  m42
};

char *tpiString[] = {
 "i160",  "i120",  "i90",  "i80",  "i72",  "i64",  "i56",  "i48",  "i44",  "i40",  "i36",  "i32",  "i28",  "i24",  "i20",  "i18",  "i16",  "i14",  "i13",  "i12",  "i11",  "i10",  "i9",  "i7",  "i6",  "m725",  "m635",  "m564",  "m508",  "m423",  "m362",  "m338",  "m317",  "m282",  "m254",  "m203",  "m169",  "m145",  "m127",  "m101",  "m84",  "m72",  "m63",  "m56",  "m50",  "m42" };

float actualRatios[] = {0.029296875, 0.0390625, 0.0520833333333, 0.05859375, 0.0651041666667, 0.0732421875, 0.0837053571429, 0.09765625, 0.106534090909, 0.1171875, 0.130208333333, 0.146484375, 0.167410714286, 0.1953125, 0.234375, 0.260416666667, 0.29296875, 0.334821428571, 0.360576923077, 0.390625, 0.426136363636, 0.46875, 0.520833333333, 0.669642857143, 0.78125, 0.0645915608628,  0.0738188976378,  0.0830463252333,  0.0922736220472,  0.110728433644,  0.129183121726,  0.13841029684,  0.147637795276,  0.166092650467,  0.184547244094,  0.230684055118,  0.276821411066,  0.322957359294,  0.369094488189,  0.461368110236,  0.5536395526,  0.645919168814,  0.738188976378,  0.830469137552,  0.922736220472,  1.1072921834};


void loadRanges(Tpi stdTpi[])
{
	stdTpi[i160].encRng = 512; stdTpi[i160].stpRng = 15; stdTpi[i160].adjCnt = 0; 
	stdTpi[i120].encRng = 128; stdTpi[i120].stpRng = 5; stdTpi[i120].adjCnt = 0; 
	stdTpi[i90].encRng = 96; stdTpi[i90].stpRng = 5; stdTpi[i90].adjCnt = 0; 
	stdTpi[i80].encRng = 256; stdTpi[i80].stpRng = 15; stdTpi[i80].adjCnt = 0; 
	stdTpi[i72].encRng = 384; stdTpi[i72].stpRng = 25; stdTpi[i72].adjCnt = 0; 
	stdTpi[i64].encRng = 1024; stdTpi[i64].stpRng = 75; stdTpi[i64].adjCnt = 0; 
	stdTpi[i56].encRng = 896; stdTpi[i56].stpRng = 75; stdTpi[i56].adjCnt = 0; 
	stdTpi[i48].encRng = 256; stdTpi[i48].stpRng = 25; stdTpi[i48].adjCnt = 0; 
	stdTpi[i44].encRng = 704; stdTpi[i44].stpRng = 75; stdTpi[i44].adjCnt = 0; 
	stdTpi[i40].encRng = 128; stdTpi[i40].stpRng = 15; stdTpi[i40].adjCnt = 0; 
	stdTpi[i36].encRng = 192; stdTpi[i36].stpRng = 25; stdTpi[i36].adjCnt = 0; 
	stdTpi[i32].encRng = 512; stdTpi[i32].stpRng = 75; stdTpi[i32].adjCnt = 0; 
	stdTpi[i28].encRng = 448; stdTpi[i28].stpRng = 75; stdTpi[i28].adjCnt = 0; 
	stdTpi[i24].encRng = 128; stdTpi[i24].stpRng = 25; stdTpi[i24].adjCnt = 0; 
	stdTpi[i20].encRng = 64; stdTpi[i20].stpRng = 15; stdTpi[i20].adjCnt = 0; 
	stdTpi[i18].encRng = 96; stdTpi[i18].stpRng = 25; stdTpi[i18].adjCnt = 0; 
	stdTpi[i16].encRng = 256; stdTpi[i16].stpRng = 75; stdTpi[i16].adjCnt = 0; 
	stdTpi[i14].encRng = 224; stdTpi[i14].stpRng = 75; stdTpi[i14].adjCnt = 0; 
	stdTpi[i13].encRng = 208; stdTpi[i13].stpRng = 75; stdTpi[i13].adjCnt = 0; 
	stdTpi[i12].encRng = 64; stdTpi[i12].stpRng = 25; stdTpi[i12].adjCnt = 0; 
	stdTpi[i11].encRng = 176; stdTpi[i11].stpRng = 75; stdTpi[i11].adjCnt = 0; 
	stdTpi[i10].encRng = 32; stdTpi[i10].stpRng = 15; stdTpi[i10].adjCnt = 0; 
	stdTpi[i9].encRng = 48; stdTpi[i9].stpRng = 25; stdTpi[i9].adjCnt = 0; 
	stdTpi[i7].encRng = 112; stdTpi[i7].stpRng = 75; stdTpi[i7].adjCnt = 0; 
	stdTpi[i6].encRng = 32; stdTpi[i6].stpRng = 25; stdTpi[i6].adjCnt = 0; 
	stdTpi[m725].encRng = 929.0; stdTpi[m725].stpRng = 60.0; stdTpi[m725].adjCnt = 11.0; 
	stdTpi[m635].encRng = 867.0; stdTpi[m635].stpRng = 64.0; stdTpi[m635].adjCnt = 75.0; 
	stdTpi[m564].encRng = 289.0; stdTpi[m564].stpRng = 24.0; stdTpi[m564].adjCnt = 214.0; 
	stdTpi[m508].encRng = 867.0; stdTpi[m508].stpRng = 80.0; stdTpi[m508].adjCnt = 75.0; 
	stdTpi[m423].encRng = 289.0; stdTpi[m423].stpRng = 32.0; stdTpi[m423].adjCnt = 214.0; 
	stdTpi[m362].encRng = 2903.0; stdTpi[m362].stpRng = 375.0; stdTpi[m362].adjCnt = 6.0; 
	stdTpi[m338].encRng = 289.0; stdTpi[m338].stpRng = 40.0; stdTpi[m338].adjCnt = 240.0; 
	stdTpi[m317].encRng = 867.0; stdTpi[m317].stpRng = 128.0; stdTpi[m317].adjCnt = 75.0; 
	stdTpi[m282].encRng = 3763.0; stdTpi[m282].stpRng = 625.0; stdTpi[m282].adjCnt = 25.0; 
	stdTpi[m254].encRng = 867.0; stdTpi[m254].stpRng = 160.0; stdTpi[m254].adjCnt = 75.0; 
	stdTpi[m203].encRng = 4439.0; stdTpi[m203].stpRng = 1024.0; stdTpi[m203].adjCnt = 35.0; 
	stdTpi[m169].encRng = 289.0; stdTpi[m169].stpRng = 80.0; stdTpi[m169].adjCnt = 199.0; 
	stdTpi[m145].encRng = 929.0; stdTpi[m145].stpRng = 300.0; stdTpi[m145].adjCnt = 11.0; 
	stdTpi[m127].encRng = 867.0; stdTpi[m127].stpRng = 320.0; stdTpi[m127].adjCnt = 75.0; 
	stdTpi[m101].encRng = 4439.0; stdTpi[m101].stpRng = 2048.0; stdTpi[m101].adjCnt = 35.0; 
	stdTpi[m84].encRng = 289.0; stdTpi[m84].stpRng = 160.0; stdTpi[m84].adjCnt = 302.0; 
	stdTpi[m72].encRng = 2903.0; stdTpi[m72].stpRng = 1875.0; stdTpi[m72].adjCnt = 6.0; 
	stdTpi[m63].encRng = 867.0; stdTpi[m63].stpRng = 640.0; stdTpi[m63].adjCnt = 75.0; 
	stdTpi[m56].encRng = 3763.0; stdTpi[m56].stpRng = 3125.0; stdTpi[m56].adjCnt = 15.0; 
	stdTpi[m50].encRng = 4439.0; stdTpi[m50].stpRng = 4096.0; stdTpi[m50].adjCnt = 35.0; 
	stdTpi[m42].encRng = 4335;/*289;*/ stdTpi[m42].stpRng = 4800;/*320;*/ stdTpi[m42].adjCnt = 148.0;

        return;
} 



class List
{

   struct Node
   {
      int step;
      void *prev;
      void *next;
   };

   struct FirstNode
   {
      int firstFlag;
      Node *prev;
      Node *next;
      int step;
      int adjCnt;
   };

   private:
      
      
 

   public:

      FirstNode *head;
      Node *lastNode;
      Node *someNode;

      //constructor
      List( ){

         head = NULL;
         
      }

      List( int value, int adjCnt){

         head = new FirstNode();
         head->firstFlag = -1;
         head->step = value;
         head->adjCnt = adjCnt;
         head->next =NULL;
         head->prev = NULL;
         lastNode = (Node *) head;
         
      }

      void addNode( int value){
         Node *n = new Node();

         n->step = value;
         n->prev = lastNode;
         lastNode->next = n;
        
         lastNode = n;

      }
      
      void wrapList(){
         lastNode->next = (Node *)head;
         head->prev = lastNode;
      }

          // destructor
      ~List(){
         FirstNode *first = head;
         Node *theNext = first->next;

         while(theNext->step != -1) {              // iterate over all elements
            Node *deleteMe = theNext;
            theNext = theNext->next;     // save pointer to the next element
            delete deleteMe;       // delete the current entry
         }
        
         delete first;
      }

};

int valMap( int val, int in_max, int out_max)
{
   int here;
   int last;

   if((in_max / out_max) < 1){

         here = ceil( (float) val /  ( (float) in_max / ((float) out_max + 1) ) );
         last = ceil( ((float) val-1) /  ( (float) in_max / ((float) out_max + 1) ) );
         return (here - last) ;
	 
   }
   else if( (in_max / out_max) < 2 ){ 
         here = ceil( (float) val /  ( (float) in_max / (float) out_max ) );
         last = ceil( ((float) val-1) /  ( (float) in_max / (float) out_max ) );
   }
   else{
         here = round( (float) val /  ( (float) in_max / (float) out_max ) );
         last = round( ((float) val-1) /  ( (float) in_max / (float) out_max ) );
   }
   
  

   if ( here - last  ) 
   {
      return 1;
   }
   else
   { 
      return 0;
   }

}

void loadLUT( Tpi stdTpi[], int threadsName, List &elitist)
{
   
   for( int i = 2; i < ( stdTpi[ threadsName ].encRng + 1 ); i++)
   {
      elitist.addNode( valMap( i, stdTpi[ threadsName ].encRng, stdTpi[ threadsName ].stpRng) );
    
   }

   elitist.wrapList();

}

void testPrintStepSum( List &fist){
   
   int step = fist.head->step;

   fist.someNode = fist.head->next;
   while(fist.someNode->step != -1) {
      step = step + fist.someNode->step;
      fist.someNode = fist.someNode->next;     
   } 
   cout << step;
   cout << '\n';
}

void testPrintRatios( Tpi stdTpi[], int i, List &listen)
{
   int step = listen.head->step;
   int adjCnt = listen.head->adjCnt;
   int adjCur = listen.head->adjCnt;
   int pulses = 0;
   listen.someNode = listen.head->next;

   for( int ham = 0; ham < 1000000; ham++){
      pulses++;

      if(listen.someNode->step == -1) {
         step = step + listen.head->step;
         listen.someNode = listen.head->next;
         adjCur--;
         if( adjCur == 0 ){
            adjCur = adjCnt;
            step = step + listen.someNode->step;
            listen.someNode = listen.someNode->next;
         }
      } 
      else{ 
         step = step + listen.someNode->step;
         listen.someNode = listen.someNode->next;
      }     
   }
 
   std::cout << "TPI name: " << tpiString[i] << "  TPI number: " << i;
   std::cout << '\n';
   std::cout << "Ratio after 1 million pulses: ";
   std::cout << std::setprecision(8) << (float) step / pulses;
   std::cout << '\n';
   std::cout << "Best case ratio: ";
   std::cout << std::setprecision(8) << actualRatios[i];
   std::cout << '\n';
   std::cout << "Ratio Error: ";
   std::cout << std::setprecision(8) << ((float) step / pulses) - actualRatios[i];
   std::cout << '\n';
   std::cout << '\n';
   
}

int main()
{

   Tpi stdTpi[46];

   loadRanges(stdTpi);   

   for( int i = 0; i < ( 46 ); i++)
   {

	List listerine( valMap( 1, stdTpi[ i ].encRng, stdTpi[ i ].stpRng), stdTpi[ i ].adjCnt);
      

	loadLUT( stdTpi, i, listerine );

      //  testPrintStepSum( listerine );

        testPrintRatios( stdTpi, i, listerine );
 
   }
}

