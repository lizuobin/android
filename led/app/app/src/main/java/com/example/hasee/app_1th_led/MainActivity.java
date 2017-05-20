package com.example.hasee.app_1th_led;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Button;
import android.view.View;
import android.widget.CheckBox;
import android.widget.Toast;
import com.example.hasee.hardlibrary.*;

public class MainActivity extends Activity {

    private Button allButton = null;
    private CheckBox checkBox1 = null;
    private CheckBox checkBox2 = null;
    private CheckBox checkBox3 = null;
    private CheckBox checkBox4 = null;
    private boolean allChecked = false;
    private HardControl hardControl = new HardControl();
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        hardControl.ledOpen();
        final Button allButton = (Button) findViewById(R.id.AllButton);
        final CheckBox checkBox1 = (CheckBox)findViewById(R.id.CheckBox_led1);
        final CheckBox checkBox2 = (CheckBox)findViewById(R.id.CheckBox_led2);
        final CheckBox checkBox3 = (CheckBox)findViewById(R.id.CheckBox_led3);
        final CheckBox checkBox4 = (CheckBox)findViewById(R.id.CheckBox_led4);

        allButton.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                // Perform action on click
                if (allChecked == true)
                {
                    allChecked = false;
                    allButton.setText("All Button off");
                    Toast.makeText(getApplicationContext(), "All Button off",
                            Toast.LENGTH_SHORT).show();
                    checkBox1.setChecked(false);
                    checkBox2.setChecked(false);
                    checkBox3.setChecked(false);
                    checkBox4.setChecked(false);
                    for (int i = 0; i < 4; i++)
                    {
                        hardControl.ledCtrl(i, 0);
                    }
                }
                else
                {
                    allChecked = true;
                    Toast.makeText(getApplicationContext(), "All Button on",
                            Toast.LENGTH_SHORT).show();
                    allButton.setText("ALL Button on");
                    checkBox1.setChecked(true);
                    checkBox2.setChecked(true);
                    checkBox3.setChecked(true);
                    checkBox4.setChecked(true);
                    for (int i = 0; i < 4; i++)
                    {
                        hardControl.ledCtrl(i, 1);
                    }
                }
            }
        });
    }

    public void onCheckboxClicked(View view) {
        // Check which checkbox was clicked
        boolean checked = ((CheckBox) view).isChecked();

        switch(view.getId()) {
            case R.id.CheckBox_led1:
                if (!checked) {
                    Toast.makeText(getApplicationContext(), "led1 off",
                            Toast.LENGTH_SHORT).show();
                    hardControl.ledCtrl(0, 0);
                }
                else {
                    Toast.makeText(getApplicationContext(), "led1 on",
                            Toast.LENGTH_SHORT).show();
                    hardControl.ledCtrl(0, 1);
                }
                break;
            case R.id.CheckBox_led2:
                if (!checked) {
                    Toast.makeText(getApplicationContext(), "led2 off",
                            Toast.LENGTH_SHORT).show();
                    hardControl.ledCtrl(1, 0);
                }
                else
                {
                    Toast.makeText(getApplicationContext(), "led2 on",
                            Toast.LENGTH_SHORT).show();
                    hardControl.ledCtrl(1, 1);
                }
                break;
            case R.id.CheckBox_led3:
                if (!checked) {
                    Toast.makeText(getApplicationContext(), "led3 off",
                            Toast.LENGTH_SHORT).show();
                    hardControl.ledCtrl(2, 0);
                }
                else
                {
                    Toast.makeText(getApplicationContext(), "led3 on",
                            Toast.LENGTH_SHORT).show();
                    hardControl.ledCtrl(2, 1);
                }
                break;
            case R.id.CheckBox_led4:
                if (!checked) {
                    Toast.makeText(getApplicationContext(), "led4 off",
                            Toast.LENGTH_SHORT).show();
                    hardControl.ledCtrl(3, 0);
                }
                else
                {
                    Toast.makeText(getApplicationContext(), "led4 on",
                            Toast.LENGTH_SHORT).show();
                    hardControl.ledCtrl(3, 1);
                }
                break;
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
