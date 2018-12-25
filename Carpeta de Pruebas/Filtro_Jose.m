% %Cargamos la data
% % Array=csvread('ECG_data.csv');
Array=csvread('ECG_Francisco_INA220.csv');
col1 = Array(:, 1); %Tiempo
col2 = Array(:, 5); %Amplitud
% %%%% FIR 
Fs = 1000;
h = fir1(350,[40]/(Fs/2),'low')
% fvtool(h,1)
% freqz(h,1,512)
% zplane(h)
% roots(h)
var = filter(h,1,col2);
% freqz(h);
%a = tf(h);
%c2d(a,0.001,'tustin')
title('ECG Original')
%figure(1),subplot(212),plot(col2);
figure(1),plot(var);
% figure(3),subplot(212),plot(col2);
% zplane(h,a)
% roots(h)

%BUTTERWORD
% 
% [B,A] = butter(5,[59 61]/(Fs/2),'stop');
% % j = filter(B,A,col2);
% [B,A] = butter (10, [0.5 40]/(Fs/2))
% % j = filter(B,A,col2);
% a = tf(A, B);
% c2d(a,0.001,'tustin')
% % freqz(B,A)
% figure(3),subplot(211),plot(j);
% figure(3),subplot(212),plot(col2);
% zplane(B,A)
% roots(B)
% freqz(B,A,Fs,Fs)
% tx = abs(fft(col2,1024))/1024;
% ty = abs(fft(h1,1024))/1024;
% F = linspace(0, Fs, 1024);
% subplot(211),plot(F, tx)
% subplot(212),plot(F,ty)



%%llamar data 
%  load('data.mat')
%   j = s(:,2);
%   j1= s(:,3);