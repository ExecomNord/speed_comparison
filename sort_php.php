<?php

function shortBubbleSort($alist) 
{
    $start = microtime(true);

    $exchanges = true;
    $passnum = count($alist) - 1;
    while ($passnum > 0 and $exchanges) 
    {
        $exchanges = false;
        for ($i = 0; $i < $passnum; $i++)
	{
            if ($alist[$i] > $alist[$i+1]) 
	    {
                $exchanges = true;
                $temp = $alist[$i];
                $alist[$i] = $alist[$i + 1];
                $alist[$i + 1] = $temp;
            }
	}
        $passnum--;
    }

    return microtime(true) - $start;
}

$totalTime = 0;
$lines = 0;
if (($handle = fopen("test_data.csv", "r")) !== FALSE) {
    while (($data = fgetcsv($handle)) !== FALSE) {
	$time = shortBubbleSort($data);
	$totalTime += $time;
	echo "Number of elements: " . count($data) . " done in: " . $time . "s\n";
    }
    fclose($handle);
}
echo "Total time: " . $totalTime . "s\n";

