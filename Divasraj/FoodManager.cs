using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FoodManager : MonoBehaviour {

    [Header("Snake Manager")]
    SnakeMovement SM;

    [Header("Food Variables")]
    public GameObject FoodPrefab;
    public int appearanceFrequency;

    [Header("Time to spawn Management")]
    public float timeBetweenFoodSpawn;
    private float thisTime;

    // Use this for initialization
    void Start () {

        //Set the Snake Movement
        SM = GameObject.FindGameObjectWithTag("SnakeManager").GetComponent<SnakeMovement>();

        //Spawn the initial Food
        SpawnFood();
    }

    // Update is called once per frame
    void Update () {

        if (GameController.gameState == GameController.GameState.GAME)
        {
            if (thisTime < timeBetweenFoodSpawn)
            {
                thisTime += Time.deltaTime;
            }
            else
            {
                SpawnFood();
                thisTime = 0;
            }
        }
    }

    public void SpawnFood()
    {
        float screenWidthWorldPos = Camera.main.orthographicSize * Screen.width / Screen.height;
        float distBetweenBlocks = screenWidthWorldPos / 5;


        for (int i = -2; i < 3; i++)
        {

            //Set the position to spawn the food
            float x = 2 * i * distBetweenBlocks;
            float y = 0;

            if(SM.transform.childCount > 0)
            {
                y = (int)SM.transform.GetChild(0).position.y + distBetweenBlocks * 2 + 10;
            }

            Vector3 spawnPos = new Vector3(x, y, 0);



            //Random Number Management
            int number;

            if (appearanceFrequency < 100)
                number = Random.Range(0, 100 - appearanceFrequency);
            else
                number = 1;



            //Actual Spawning step
            GameObject boxInstance;

            if(number == 1)
                boxInstance = Instantiate(FoodPrefab, spawnPos, Quaternion.identity, transform);

        }
    }
}
