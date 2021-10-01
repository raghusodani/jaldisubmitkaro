using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BlocksManager : MonoBehaviour {

    [Header("Snake Manager")]
    public SnakeMovement SM;
    public float distanceSnakeBarrier;

    [Header("Block Prefab")]
    public GameObject BlockPrefab;

    [Header("Time to spawn Management")]
    public float minSpawnTime;
    public float maxSpawnTime;
    private float thisTime;
    private float randomTime;

    [Header("Snake Values for Spawning")]
    public int minSpawnDist;
    Vector2 previousSnakePos;
    public List<Vector3> SimpleBoxPositions = new List<Vector3>();

	// Use this for initialization
	void Start () {

        //Initialize this time
        thisTime = 0;

        //Spawn the First Barrier
        SpawnBarrier();

        //Set a random time to spawn blocks
        randomTime = Random.Range(minSpawnTime, maxSpawnTime);

	}
	
	// Update is called once per frame
	void Update () {

        if (GameController.gameState == GameController.GameState.GAME)
        {
            if (thisTime < randomTime)
            {
                thisTime += Time.deltaTime;
            }
            else
            {
                    SpawnBlock();
                    thisTime = 0;
                    randomTime = Random.Range(minSpawnTime, maxSpawnTime);
            }


            //Spawning management
            if (SM.transform.childCount > 0)
            {
                if (SM.transform.GetChild(0).position.y - previousSnakePos.y > minSpawnDist)
                {
                    SpawnBarrier();
                }
            }
        }
	}

    public void SpawnBarrier()
    {
        float screenWidthWorldPos = Camera.main.orthographicSize * Screen.width / Screen.height;
        float distBetweenBlocks = screenWidthWorldPos / 5;


        for(int i = -2; i < 3; i++)
        {
            float x = 2 * i * distBetweenBlocks;
            float y = 0;

            if (SM.transform.childCount > 0)
            {
                y = (int)SM.transform.GetChild(0).position.y + distBetweenBlocks * 2 + distanceSnakeBarrier;

                if (Screen.height / Screen.width == 4 / 3)
                    y *= 4/3f;
            }

            Vector3 spawnPos = new Vector3(x, y, 0);

            GameObject boxInstance = Instantiate(BlockPrefab, spawnPos, Quaternion.identity, transform);

            //Save the Head Position
            if(SM.transform.childCount > 0)
                previousSnakePos = SM.transform.GetChild(0).position;

        }

    }

    public void SpawnBlock()
    {
        float screenWidthWorldPos = Camera.main.orthographicSize * Screen.width / Screen.height;
        float distBetweenBlocks = screenWidthWorldPos / 5;

        int random;
        random = Random.Range(-2, 3);

        float x = 2 * random * distBetweenBlocks;
        float y = 0;

        if (SM.transform.childCount > 0)
        {
            y = (int)SM.transform.GetChild(0).position.y + distBetweenBlocks * 2 + distanceSnakeBarrier;

            if (Screen.height / Screen.width == 4 / 3)
                y *= 2;

        }


        Vector3 spawnPos = new Vector3(x, y, 0);

        //Boolean to spawn or not regarding the position
        bool canSpawnBlock = true;

        //If there are no positions in the list, add this one
        if (SimpleBoxPositions.Count == 0)
            SimpleBoxPositions.Add(spawnPos);
        else
        {
            //Check if the position is already used or not
            for (int k = 0; k < SimpleBoxPositions.Count; k++)
            {
                if (spawnPos == SimpleBoxPositions[k])
                    canSpawnBlock = false;
            }
        }

        GameObject boxInstance;

        if (canSpawnBlock)
        {
            //Add the position to the list
            SimpleBoxPositions.Add(spawnPos);

            //Debug.Log(SimpleBoxPositions.Count);

            boxInstance = Instantiate(BlockPrefab, spawnPos, Quaternion.identity, transform);

            boxInstance.name = "SimpleBox";
            boxInstance.tag = "SimpleBox";

            //Change the layer to hit the normal boxes
            boxInstance.layer = LayerMask.NameToLayer("Default");
            //boxInstance.GetComponent<BoxCollider2D>().isTrigger = true;

            boxInstance.AddComponent<Rigidbody2D>();
            boxInstance.GetComponent<Rigidbody2D>().constraints = RigidbodyConstraints2D.FreezeAll;
        }

    }

    public void SetPreviousSnakePosAfterGameover()
    {
        Invoke("PreviousPosInvoke", 0.5f);
    }

    void PreviousPosInvoke()
    {
        previousSnakePos.y = SM.transform.GetChild(0).position.y;
    }
}
