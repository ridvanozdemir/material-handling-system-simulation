close all;

load('as1.mat')
load('as2.mat')
load('as3.mat')
load('as4.mat') 

 figure
 plot(as1(1,:),as1(2,:),'k',as2(1,:),as2(2,:),'g',as3(1,:),as3(2,:),'r',as4(1,:),as4(2,:),'m');
 legend('asans�r1','asans�r2','asans�r3','asans�r4');
 xlabel('Zaman (sn)');
 ylabel('Dagitilan Kasa Say�s�');
 title('Zamana Bagli Kasa Dagitimi');