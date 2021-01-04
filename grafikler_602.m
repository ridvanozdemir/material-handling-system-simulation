close all;


load('yuk1a1.mat')
load('yuk1a2.mat')
load('yuk2a1.mat')
load('yuk2a2.mat')
load('yuk3a1.mat')
load('yuk3a2.mat')
load('yuk1p1.mat')
load('yuk1p2.mat')
load('yuk2p1.mat')
load('yuk2p2.mat')
load('yuk3p1.mat')
load('yuk3p2.mat')

 figure
 
% %yuk 1 icin belli bir periyod için
%  plot(yuk1p1(1,:)/60,yuk1p1(2,:),'k', yuk1p2(1,:)/60,yuk1p2(2,:),'r-.');
% %yuk 2 icin
%  plot(yuk2p1(1,:)/60,yuk2p1(2,:),'k', yuk2p2(1,:)/60,yuk2p2(2,:),'r-.');
% %yuk 3 icin
%   plot(yuk3p1(1,:)/60,yuk3p1(2,:),'k', yuk3p2(1,:)/60,yuk3p2(2,:),'r-.');

% %yuk 1 icin belli adet için
%    plot(yuk1a1(1,:)/60,yuk1a1(2,:),'k', yuk1a2(1,:)/60,yuk1a2(2,:),'r-.');
% %yuk 2 icin
%    plot(yuk2a1(1,:)/60,yuk2a1(2,:),'k', yuk2a2(1,:)/60,yuk2a2(2,:),'r-.');
% %yuk 3 icin
%   plot(yuk3a1(1,:)/60,yuk3a1(2,:),'k', yuk3a2(1,:)/60,yuk3a2(2,:),'r-.'); 
 
 legend('ara baglantisiz','ara baglantili');
 xlabel('Zaman (dakika)');
 ylabel('Dagitilan Kasa Sayısı');
 title('Zamana Bagli Kasa Dagitimi');