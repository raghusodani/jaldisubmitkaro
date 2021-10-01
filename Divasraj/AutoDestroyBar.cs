using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AutoDestroyBar : MonoBehaviour {

    [Header("Snake Movement")]
    SnakeMovement SM;

	// Use this for initialization
	void Start () {
        //Set the Snake Movement
        SM = GameObject.FindGameObjectWithTag("SnakeManager").GetComponent<SnakeMovement>();

    }

    // Update is called once per frame
    void Update () {
        if (SM.transform.childCount > 0 && transform.position.y - SM.transform.GetChild(0).position.y < -10)
            Destroy(this.gameObject);
    }


}
