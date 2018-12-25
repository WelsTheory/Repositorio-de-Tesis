Filename='104';
[sig, Fs, tm] = rdsamp('mitdb/104', 1);
%plot(tm,sig)
tm_tmp = downsample(tm,1);
sig_tmp= downsample(sig,1); 
plot(tm_tmp(1:72223),sig_tmp(1:72223))

%save('ECGRAW104.txt','sig_tmp','-ascii','-tabs');
%type('ECGRAW104.txt');
sig_tmp=round ((sig_tmp+1)*80);
%sig_tmp=round ((sig_tmp+1.5)*40);
%plot(sig_tmp(1:500));
plot(sig_tmp(1:1000));
sig_tmp1=transpose(sig_tmp);
%csvwrite('ECGRAW.txt',sig_tmp1(1:1000));
%type('ECGRAW.txt')
%fid = fopen ("ECGRAW.txt", "w");
%fdisp (fid, "%.3f",sig_tmp);
%fclose (fid);
