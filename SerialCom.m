%% Preparing the serial communication
% https://www.mathworks.com/help/matlab/import_export/read-streaming-data-from-arduino.html
% This is the MATLAB file that reads the Serial port for any in-coming information 

% Clear the workspace
% Select the correct port and correct Baudrate
% Set the terminator to "CR/LF" (CR = Carriage Return and LF = Line Feed)
clc; clear; close all; format compact; format shortG
s = serialport('COM7', 115200);
configureTerminator(s, "CR/LF");

%% Use this code to read data from the serial port
% Flush the previous data
% Read the data from the serial COM
% Break the loop with Ctrl+C
flush(s);
while 1
    % The microcontroller sends float number only, that are separated by a comma. 
    data = str2double(strsplit(readline(s), ','))  
end
