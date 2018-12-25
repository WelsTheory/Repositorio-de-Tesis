
%run("Physionet_Init.m"); 
%global sig_tmp1
[sig, Fs, tm] = rdsamp('mitdb/103', 1);
%plot(tm,sig)
tm_tmp = downsample(tm,9);
sig_tmp= downsample(sig,9); 
plot(tm_tmp(1:500),sig_tmp(1:500))

%save('ECGRAW104.txt','sig_tmp','-ascii','-tabs');
%type('ECGRAW104.txt');
sig_tmp=round ((sig_tmp+1.5)*40);
plot(sig_tmp(1:500));
sig_tmp1=transpose(sig_tmp);
plot(sig_tmp1(1:500));

%25ms
%tm_tmp=truncate (tm_tmp(1:3000),(3:-1),@round);
%tm_tmp1=transpose(tm_tmp(1:3000));

%csvwrite('ECGRAW_Sig.txt',sig_tmp1(1:500));
%type('ECGRAW_Sig.txt');
%csvwrite('ECGRAW_tm.txt',tm_tmp1(1:3000));
%type('ECGRAW_tm.txt');
