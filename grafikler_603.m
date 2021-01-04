close all;


 figure
%adet sayýsý girilen sistemin sürelerinin kýyaslanmasý
 %y=[51896 51896;40847 35516;35378 29088];
 %bar(y);
 
 %periyot zamaný girilen sistemlerin kýyaslanmasý yük 1
%  y=[61 61;54 54;57 57; 47 47];
%  bar(y); 
%  yuk 2
%  y=[59 77;84 76;60 87; 77 77];
%  bar(y); 
 %yük 3
  y=[796 795;591 533;591 479];
  bar(y);
%plot(a1a3y1(1,:),a1a3y1(2,:),'b',a2a3y1(1,:),a2a3y1(2,:),'r');
%legend('asansör3_1','asansör3_2');
%  plot(as1(1,:),as1(2,:),'b',as2(1,:),as2(2,:),'g',as3(1,:),as3(2,:),'r',as4(1,:),as4(2,:),'m',bs1(1,:),bs1(2,:),bs2(1,:),bs2(2,:),bs3(1,:),bs3(2,:),bs4(1,:),bs4(2,:));
%  legend('asansör1_1','asansör2_1','asansör3_1','asansör4_1','asansör1_2','asansör2_2','asansör3_2','asansör4_2');
xlabel('Zaman (dakika)');
ylabel('Dagitilan Kasa Sayýsý');
title('Zamana Bagli Kasa Dagitimi');