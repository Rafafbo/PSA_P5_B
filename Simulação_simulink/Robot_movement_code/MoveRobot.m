clc
clear
close

hipLOffset = pi/2;
kneeLOffset = pi/2;
ankleLOffset = -pi/2;
hipROffset = -pi/2;
kneeROffset = -pi/2;
ankleROffset = pi/2;

hipL = hipLOffset;
kneeL = kneeLOffset;
ankleL = ankleLOffset;
hipR = hipROffset;
kneeR = kneeROffset;
ankleR = ankleROffset;

stepHeight = 10;
stepClearance = 1;

A = initialize(stepHeight);

N = 20;
B = zeros(6,18*N);
idx = 1;
idz = 18;
for i = 1:N
    C = takeStep(2,0,stepHeight,stepClearance);
    B(:,idx:idz) = C;
    idx = i*18+1;
    idz = (i+1)*18;
end

Z = zeros(6,8+18*N);
Z(:,1:8) = A;
Z(:,9:8+18*N) = B;
Z = rad2deg(Z);
nomes = {'hipL','kneeL','ankleL','hipR','kneeR','ankleR'};
for i = 1:6
    plot(Z(i,:), 'DisplayName', nomes{i})
    legend()
    hold on
end
PernaEsq = Z(1:3,:);
PernaDir = Z(4:6,:);
save('PernaEsq.mat','PernaEsq');
save('PernaDir.mat','PernaDir');


    