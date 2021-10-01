using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FoodBehavior : MonoBehaviour {

    [Header("Snake Manager")]
    SnakeMovement SM;

    [Header("Food Amount")]
    public int foodAmount;

    // Use this for initialization
    void Start () {
        SM = GameObject.FindGameObjectWithTag("SnakeManager").GetComponent<SnakeMovement>();

        foodAmount = Random.Range(1, 10);

        transform.GetComponentInChildren<TextMesh>().text = "" + foodAmount;
    }

    // Update is called once per frame
    void Update () {
        if (SM.transform.childCount > 0 && transform.position.y - SM.transform.GetChild(0).position.y < -10)
            Destroy(this.gameObject);
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        Destroy(this.gameObject);
    }
}
