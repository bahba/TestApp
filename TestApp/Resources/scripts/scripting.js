var boomSignal = false;
var kapowSignal = false;
var clearSignal = false;

function boomSignalEmitted()
{
    boomSignal = true;
    return true;
}
function kapowSignalEmitted()
{
    kapowSignal = true;
    return true;
}
function clearScreenSignalEmitted()
{
    clearSignal = true;
    return true;
}

testapp.signalBoomTriggered.connect(boomSignalEmitted);
testapp.signalKapowTriggered.connect(kapowSignalEmitted);
testapp.signalClearScreenTriggered.connect(clearScreenSignalEmitted);

// print("this is printed in script scripting.js");
//testapp.method("method(): ");


//testapp.boomTriggered();
if (boomSignal)
{
    print("testapp.boomTriggered(): OK");
//    testapp.signalBoomTriggered.disconnect(boomSignalEmitted);
    boomSignal = false;
}
else if (!boomSignal)
{
    print("testapp.boomTriggered(): FAIL!");
}


//testapp.kapowTriggered();
if (kapowSignal)
{
    print("testapp.kapowTriggered(): OK");
//    testapp.signalKapowTriggered.disconnect(kapowSignalEmitted);
    kapowSignal = false;
}
else if (!kapowSignal)
{
    print("testapp.kapowTriggered(): FAIL!");
}


//testapp.clearScreenTriggered();
if (clearSignal)
{
    print("testapp.clearScreenTriggered(): OK");
//    testapp.signalClearScreenTriggered.disconnect(clearScreenSignalEmitted)
    clearSignal = false;
}
else if (!clearSignal)
{
    print("testapp.clearScreenTriggered(): FAIL!");
}


testapp.comboBoxPickImgTriggered(TestApp.KAPOW);
if (kapowSignal && !boomSignal)
{
    print("\ntestapp.comboBoxPickImgTriggered(TestApp.KAPOW): OK");
    testapp.signalKapowTriggered.disconnect(kapowSignalEmitted);
    kapowSignal = false;
}
else if (kapowSignal == false && boomSignal == true)
{
    print("\ntestapp.comboBoxPickImgTriggered(TestApp.KAPOW): FAIL! _BOOM_ triggered instead");
    testapp.signalBoomTriggered.disconnect(boomSignalEmitted);
    boomSignal = false;
}
else if (kapowSignal == false && boomSignal == false)
{
    print("WTH?!");
}



//print("testapp.comboBoxPickImgTriggered(TestApp.BOOM)": );
//testapp.comboBoxPickImgTriggered(TestApp.BOOM);
//if (boomSignal == true)
//{
//    print("testapp.boomTriggered(): OK");
//}
//if (boomSignal == false)
//{
//    print("testapp.boomTriggered(): FAIL!");
//}
//testapp.signalBoomTriggered.disconnect(boomTriggered);
//boomSignal = false;

