function voltaje=ADC_Serial(muestras)

close all;
clc;
voltaje = 0;

puerto = serial('COM3');
fopen(puerto);

contador = 1;

figure('Name','Grafica de voltaje')
title('GRAFICA ADC_ Serial');
xlabel('Numero de muestras');
ylabel('Voltaje V');
grid on;
hold on;

while contador<=muestras
    ylim([0 5.1]);
    xlim([0 contador+50]);
    valorADC = fscanf(puerto,'%d');
    voltaje(contador) = valorADC(1)*5/1024;
    plot(voltaje);
    drawnow
    contador = contador + 1;
end

fclose(puerto);
