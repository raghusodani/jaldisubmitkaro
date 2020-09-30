using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraMovement : MonoBehaviour {

    [Header("Snake Container")]
    public Transform SnakeContainer;

    Vector3 initialCameraPos;

	// Use this for initialization
	void Start () {

        initialCameraPos = transform.position;	
	}
	
	// Update is called once per frame
	void Update () {
        if(SnakeContainer.childCount > 0)
            transform.position = Vector3.Slerp(transform.position, 
                (initialCameraPos + new Vector3(0,SnakeContainer.GetChild(0).position.y - Camera.main.orthographicSize/2,0)),
                0.1f);
	}
}
