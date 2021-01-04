close all;

load('as1.mat')
load('as2.mat')
load('as3.mat')
load('as4.mat') 

 figure
 plot(as1(1,:),as1(2,:),'k',as2(1,:),as2(2,:),'g',as3(1,:),as3(2,:),'r',as4(1,:),as4(2,:),'m');
 legend('asansör1','asansör2','asansör3','asansör4');
 xlabel('Zaman (sn)');
 ylabel('Dagitilan Kasa Sayýsý');
 title('Zamana Bagli Kasa Dagitimi');