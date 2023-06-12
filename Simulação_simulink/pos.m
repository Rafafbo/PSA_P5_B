function Q = pos(x, z, leg)
    l1 = 5;
    l2 = 5.7;
    
    hipRad2 = atan(x/z);
    z2 = z/cos(hipRad2);
    hipRad1 = acos((l1^2 + z2^2 - l2^2)/(2*l1*z2));
    hipRad = hipRad1 + hipRad2;

    kneeRad = pi - acos((l1^2 + l2^2 - z2^2)/(2*l1*l2));
    
    ankleRad = pi/2 + hipRad2 - acos((l2^2 + z2^2 - l1^2)/(2*l2*z2));

    B = updateServoPos(hipRad, kneeRad, ankleRad, leg);

    Q = B;
end