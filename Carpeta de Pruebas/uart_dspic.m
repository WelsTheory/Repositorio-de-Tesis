% Delete Opened Ports in MATLAB
delete(instrfind)
% Create a Serial Object
ser = serial('COM4', 'BaudRate',57600, 'Timeout',10);

DATA_SIZE = 100;
temperature = zeros(DATA_SIZE, 1);
% timestamp = zeros(DATA_SIZE, 1);
% timestamp = datetime(timestamp, timestamp, timestamp);
% for i = 1:DATA_SIZE
%    timestamp(i) = datetime;
% end
index = 1;

% Open Communication Port
fopen(ser);
while true
    temp = fscanf(ser);
        if index < DATA_SIZE
            index = index+1;
        else
            % Reset Subscript Index
            index = 1;
        end
        temperature(index) = str2double(temp);
        % Time Stamp Temperature Values
        % timestamp(index) = datetime;
        % plot(timestamp, temperature, 'LineWidth',2,'Color',[0,0,1.0])
        plot(temperature, 'LineWidth',2,'Color',[0,0,1.0])
        ylim([0,80])
        xlabel('Time \rightarrow')
        ylabel('Temperature (C)\rightarrow');
        title('Real-Time Temperature Plot');
        drawnow
end

fclose(ser);
