function boomSignalEmitted(emitted)
{
    if (emitted)
        result = "OK";
    else if (!emitted)
        result = "FAIL";

    print("testapp.signalBoomTriggered( " + emitted + " ): result == " + result);
}
function kapowSignalEmitted(emitted)
{
    if (emitted)
        result = "OK";
    else if (!emitted)
        result = "FAIL";
        
    print("testapp.signalKapowTriggered( " + emitted + " ): result == " + result);
}
function clearScreenSignalEmitted(emitted)
{
    if (emitted)
        result = "OK";
    else if (!emitted)
        result = "FAIL";

    print("testapp.signalClearScreenTriggered( " + emitted + " ): result == " + result);
}
testapp["signalBoomTriggered(bool)"].connect(boomSignalEmitted);
testapp["signalKapowTriggered(bool)"].connect(kapowSignalEmitted);
testapp["signalClearScreenTriggered(bool)"].connect(clearScreenSignalEmitted);

// print("this is printed in script scripting.js");
//testapp.method("who is the doctor");


testapp.boomTriggered();
testapp.kapowTriggered();
testapp.clearScreenTriggered();

testapp.comboBoxPickImgTriggered(TestApp.KAPOW);
testapp.comboBoxPickImgTriggered(TestApp.BOOM);


////print("testapp.comboBoxPickImgTriggered(TestApp.BOOM)": );
////testapp.comboBoxPickImgTriggered(TestApp.BOOM);

