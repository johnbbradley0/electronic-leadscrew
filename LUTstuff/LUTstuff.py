import fractions as f
import math as m

stepRes = 200
stepDiv = 8
leadTpi = 12
encRes = 4096

def valMap(val, in_min, in_max, out_min, out_max):

   return (val - in_min) * (out_max - out_min)/(in_max -in_min) + out_min 


def findLowerGCD( someSteps, somePulse):
    
   i = 1

   numbers = [ f.gcd( someSteps + 0, somePulse + i ), 
          f.gcd( someSteps + 0, somePulse - i ), 
          f.gcd( someSteps + i, somePulse + 0 ),
          f.gcd( someSteps - i, somePulse + 0 ) ]

   numbers.sort(reverse = True)
   n = numbers[0]

   while round(somePulse/n) > 5000: 
      i = i + 1 

      n = f.gcd( someSteps + 0, somePulse + i )

   return n, someSteps, somePulse + i, i, "pos_enc"  

bigStep = stepRes * stepDiv * leadTpi

tpi = [160, 120, 90, 80, 72, 64, 56, 48, 44, 
        40,  36, 32, 28, 24, 20, 18, 16, 14, 
        13,  12, 11, 10,  9,  7,  6]


tpmm = [0.35, 0.4, 0.45,  0.5, 0.6,  0.7, 0.75,
         0.8, 0.9,    1, 1.25, 1.5, 1.75,    2, 
         2.5,   3,  3.5,    4, 4.5,    5,    6]


m_tpi = [ round((25.4 / i) *10000 ) for i in tpmm]

for atpi in tpi:
   print( ' i' + str(atpi) + ',' ), 

for atpi in m_tpi:
   print( ' m' + str( int(atpi/1000) ) + ',' ), 

print '\n'

for atpi in tpi:
   print( ' "i' + str(atpi) + '",' ), 

for atpi in m_tpi:
   print( ' "m' + str( int(atpi/1000) ) + '",' ), 

print '\n'

for atpi in tpi:
   print( str(  bigStep / ( encRes * float(atpi) ) ) + ',' ),

for atpi in m_tpi:
   print( str( bigStep*10000 / ( encRes * atpi ) )  + ', ' ), 

print '\n'

for atpi in tpi:

   bigEnc = encRes * atpi

   gearGcd = f.gcd(bigStep,bigEnc)

   encRange = bigEnc/gearGcd

   stepRange = bigStep/gearGcd

   adjustCount = 0;

   print( 'stdTpi[i' + str(atpi) + '].encRng = ' + str(encRange) + '; ' + 
          'stdTpi[i' + str(atpi) + '].stpRng = ' + str(stepRange) + '; ' + 
          'stdTpi[i' + str(atpi) + '].adjCnt = ' + str(adjustCount) + '; ')


for atpi in m_tpi:

   bigEnc = encRes * atpi

   gearGcd = f.gcd(bigStep*10000, bigEnc)

   encRange = 10*(bigEnc/gearGcd)
   
   stepRange = 100000*(bigStep/gearGcd)

   newGearGcd = 0
   newBigStep = 0
   newBigEnc = 0
    
   if encRange > 5000:
     
      newGearGcd, newBigStep, newBigEnc, fix, fixType = findLowerGCD( bigStep*10000, bigEnc )
   
      newEncRange = newBigEnc/newGearGcd

      newStepRange = newBigStep/newGearGcd

      adjustCount = m.floor(newGearGcd/fix) 
	
      adjusts = m.floor(newBigEnc / adjustCount)

      print( 'stdTpi[m' + str( int(atpi/1000) ) + '].encRng = ' + str(newEncRange) + '; ' +
             'stdTpi[m' + str( int(atpi/1000) ) + '].stpRng = ' + str(newStepRange) + '; ' +
             'stdTpi[m' + str( int(atpi/1000) ) + '].adjCnt = ' + str(adjustCount) + '; ' )


      #print( str( (adjusts * adjustCount) - bigEnc) +'\n') 
      #print( str( (newEncRange - adjusts) - bigEnc  ) +'\n') 
   
   else:
      print(  str(bigEnc) + ' ' + str(bigStep*10000) + '\n' )

